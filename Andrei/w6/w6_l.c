#include <stdio.h>
#include <string.h>

#define NUMBER_BLA 5.5

#define LIST_SIZE 100

typedef float my_float_idk;


struct student{
    int age;
    int year_study;
    float grade;
    char name[100];
};

void mult_print(int a, int b){

    // int a;
    // int b;

    // scanf("%d", &a);
    // scanf("%d", &b);

    int res = a*b;


    printf("Hello whatever %d idk \n", res);

}

int sum_ret(int a, int b){

    int res = a + b;
    // res+=2;
    return res;

}

void find_no_div_x_y(int x, int y){

    int l[LIST_SIZE];

    int to_insert = 0;
    int last_i = 0;

    while(last_i < LIST_SIZE){

        if(to_insert % x == 0 && to_insert % y == 0){
            l[last_i] = to_insert;
            last_i+=1;
        }

        to_insert+=1;
    }

    // printf("l[%d] = %d\n",1, l[1]);


    for(int i=0; i<LIST_SIZE; i++){
        printf("l[%d] = %d\n",i, l[i]);
    }

}

int main(){


    // mult_print(2, 3);
    // mult_print(5, 7);
    // mult_print(10, 10);
    // mult_print(6, -4);
    // mult_print(9, 0);

    // int a = 5;
    // int res = sum_ret(a, 3);

    // printf("result of sum_red(%d, %d) = %d\n", a, 3, sum_ret(a, 3));

    // for(int i = 10; i <= 100; i = i+2){

    //     printf("result of sum_red(%d, %d) = %d\n", i, 0, sum_ret(i, 0));

    // }

    // int index = 0;

    // while(index <= 100){

    //     index++;


    //     if(index % 4 == 0 && index % 3 == 0){
    //         printf("%d: result of sum_red(%d, %d) = %d\n",index, index, 0, sum_ret(index, 0));
    //     }
    //     else {
    //         printf("%d: Index not divisible by 3 AND 4\n", index);
    //     }

    // }

    // float a = 4.5;

    // printf("%f\n", a);

    // printf("#define NUMBER_BLA %f\n", NUMBER_BLA);

    // printf("#define NUMBER_BLA %f\n", NUMBER_BLA);
    // printf("#define NUMBER_BLA %f\n", NUMBER_BLA);

    // my_float_idk a = 5.5;
    // printf("flll %f\n", a);

    struct student st1;

    st1.age = 20;
    st1.grade = 10;
    st1.year_study = 1;
    strcpy(st1.name, "Ismail");

    struct student st2;

    st2.age = 21;
    st2.grade = 2;
    st2.year_study = 2;
    strcpy(st2.name, "Dulan");

    // printf("name: %s, %s\n", st1.name, st2.name);

    printf("age: %d, grade: %f, yos: %d, name: %s\n", st2.age, st2.grade, st2.year_study, st2.name);
    // // printf("name: %s \n", st2.name);

    // find_no_div_x_y(10, 3);

    return 0;
}