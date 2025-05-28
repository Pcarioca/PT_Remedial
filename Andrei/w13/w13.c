#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef union{

    uint32_t buffer;
    char string[4];

}inp;

int main(int argc, char* argv[]){


    if(argc!=3){
        printf("format: %s <file_to_read> <output_file>\n", argv[0]);
        exit(0);
    }

    inp input;

    FILE* f = fopen(argv[1], "rb");

    FILE* out = fopen(argv[2], "wt");

    if(!f){
        printf("File error\n");
        exit(0);
    }

    if(!out){
        printf("File out error\n");
        exit(0);
    }



    while(!feof(f)){

        if( fread(&input.buffer, 5, 1, f) == 0 ){
            printf("fgets error\n");
            exit(0);
        }

        if((input.buffer & 0x55u) == 0x55u){
            fprintf(out, "uint: %u\n", input.buffer);
        } else if((input.buffer & 0x98u) == 0x98u){
            fprintf(out, "text: %s\n", input.string);
        }

        if( fseek(f, 5, SEEK_CUR)!=0 ){
            printf("Seek error\n");
            exit(0);
        }

        
    }

    fclose(f);

    // int a;
    // float b;
    // char s[100];

    // int v[3];

    // printf("Enter an integer, a float, and a word: ");
    // int count = scanf("%d %f %99s", &a, &b, s);

    // for(int i=0; i<=2; i++){
    //     scanf("%d", &v[i]);
    // }

    // for(int i=0; i<=2; i++){
    //     printf("%d\n", v[i]);
    // }



    // if (count == 3) {
    //     printf("You entered: %d, %f, %s\n", a, b, s);
    // } else {
    //     printf("Input error: only %d items read\n", count);
    // }

    return 0;
}