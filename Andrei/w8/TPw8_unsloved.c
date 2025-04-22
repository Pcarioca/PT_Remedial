/*
    This code was used just to exaplin the theory part of lab 3
    This code does not do anything uyseful in itself,
    just exemplifies some things you need to know for the lab


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct song { 
    int year;
    char name[30];
    char auth[30];

} songs;


void free_all(int size, songs* s){
    for(int i=0; i<size; i++){
        free(s + i);
    }
}

int main(int argc, char* argv[]){

    // char name[30];
    // char auth[30];
    // int year;

    int allocated_mem;

    // songs list[100];

    songs* s_start;
    s_start = (songs*)malloc(100*sizeof(songs));

    if(s_start == NULL){
        printf("malloc failed");
        exit(0);
    }
    allocated_mem = 100;


    FILE* in = fopen(argv[1], "rt");

    if(in == NULL){

        printf("file not found\n");
        exit(0);

    }
    int i = 0;

    while(fscanf(in, "%s %s %d", s_start[i].name, s_start[i].auth, &s_start[i].year) == 3){

        if(i==100){
            s_start = realloc(s_start, i + 100);
        }
        allocated_mem = i + 100;
        printf("Name is %s, year is %d, auth: %s\n", s_start[i].name, s_start[i].year, s_start[i].auth);
        i++;
    }

    // printf("Name is %s, year is %d, auth: %s\n", name, year, auth);

    fclose(in);
    free_all(allocated_mem, s_start);
}