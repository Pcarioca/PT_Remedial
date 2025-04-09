#include <stdio.h>
#include <string.h>

#define ARR_LEN 6

void print_age(int age, char name[]){

    // int age;

    // age = 20;

    printf("%s is %d years old\n", name ,age);

}

int dbl(int x){
    int d;

    d = x*2;

    return d;

}

struct person{
    char name[20];
    int age;
    float grade;
};

int main(){

    // printf("Mert\n");

    print_age(21, "Andrei");
    print_age(29, "Gayathri");
    print_age(21, "Andrei");

    // int no_calls = 10;

    // int age = 0;

    // int i;

    // for(i = 0; i < no_calls; i = i + 1){
    //     print_age(i, "I");
    // }

    // i = 0;

    // while(i < no_calls){
    //     print_age(i, "I");

    //     i = i + 1;
    // }

    // int idk = 10;


    // printf("The double of %d is %d\n", idk, dbl(10));

    // for(int i = 0; i < 15; i = i + 3){
    //     // printf("%d\n", dbl(i));
    //     print_age(dbl(i), "I");
    // }

    // int int_arr[ARR_LEN];

    // for(int ind = 0; ind<ARR_LEN; ind++){
    //     // int_arr[ind] = 2*ind;
    //     scanf("%d", &int_arr[ind]); //& = referentiator
    // }

    // for(int ind = 0; ind<ARR_LEN; ind++){
    //     // int_arr[ind] = 2*ind;
    //     printf("int_arr[%d] = %d\n", ind, int_arr[ind]);
    // }

    struct person p1;

    strcpy(p1.name, "Andrei");
    p1.age = 21;
    p1.grade = 9.99;

    printf("%s is %d years old and his grade at PT is %f\n", p1.name, p1.age, p1.grade);

    struct person p[ARR_LEN];

    for(int ind = 0; ind<ARR_LEN; ind++){

        strcpy(p[ind].name, "Andrei");
        p[ind].age = ind;
        p[ind].grade = 0.5678 * ind + 4;
        
    }

    for(int ind = 0; ind<ARR_LEN; ind+=1){

        printf("%s is %d years old and his grade at PT is %f\n", p[ind].name, p[ind].age, p[ind].grade);
        
    }



    

    return 0;
}