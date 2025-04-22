

#include <stdio.h>
#include <stdlib.h>


/* Working Program */

typedef struct song { 
    int year;
    char name[30];
    char auth[30];

} songs;


void free_all(int size, songs* s){
    // for(int i=0; i<size; i++){
        free(s);
    // }
}

void print_record(songs s){
    printf("Name is %s, year is %d, auth: %s\n", s.name, s.year, s.auth);
}

int main(int argc, char* argv[]){

    // char name[30];
    // char auth[30];
    // int year;

    if(argc != 3){
        printf("Usage: %s <file> <year>", argv[0]);
        exit(0);
    }

    int allocated_mem = 0;

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

        if(i==allocated_mem){
            s_start = realloc(s_start, (i + 100) * sizeof(songs));
            allocated_mem = i + 100;

            if(s_start == NULL){
                printf("malloc failed");
                exit(0);
            }
        }
       
        // printf("Name is %s, year is %d, auth: %s\n", s_start[i].name, s_start[i].year, s_start[i].auth);
        i++;
    }

    for(int j = 0; j<i; j++){
        if(s_start[j].year == atoi(argv[2])){
            print_record(s_start[j]);
        }
    }

    // printf("Name is %s, year is %d, auth: %s\n", name, year, auth);

    fclose(in);
    free_all(allocated_mem, s_start);
}

/*
Homework:

    -Modularize the program: after line 52, 
    the program only calls funtions to fill in the struct,
    to print everything, and to free the memory and the file.
*/