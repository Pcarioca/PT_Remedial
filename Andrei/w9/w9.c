#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person {
    char name[20];
    int age;
    float height;
} person;

typedef struct node {
    person p;
    struct node* next;
    // struct node* prev;
} node;

node* create_node(char* name, int age, float height){

    node* to_create = (node*)malloc(sizeof(node));

    if(!to_create){
        printf("Malloc failed\n");
        exit(EXIT_FAILURE);
    }

    (*to_create).p.age = age; //technically correct
    to_create->p.height = height;
    strcpy(to_create->p.name, name);

    to_create->next = NULL;

    return to_create;

}

void add_node(node* head, char* name, int age, float height){

    if(head == NULL){
        head = create_node(name, age, height);
    } else {
        node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }

        curr->next = create_node(name, age, height);
    }

}

void free_all(node* head){
    node* to_delete;

    while(head!=NULL){
        to_delete = head;
        head = head->next;
        free(to_delete);
    }
}

void print_person(person p){
    static int index = 0;
    printf("person #%d: Name: %s, Age: %d, Height: %.1f\n", index, p.name, p.age, p.height);
    index += 1;
}

void print_all(node* head){
    node* to_print;

    while(head!=NULL){
        to_print = head;
        head = head->next;
        print_person(to_print->p);
        // free(to_delete);

    }
}

int main() {
    
    node* head = NULL;
    head = create_node("Gaiya",29,5.4);
    add_node(head, "shehara",24,5.0);
    // TO DO:
    // add_node_sorted(head, "shehara",24,5.0);
    add_node(head, "Mert",21,5.7);

    /*
        homework: Implement add_node_sorted( ... ) which inserts nodes sorted in order according to 
        the age of each person.

        To check if you did it correctly, print_all must print them in order without changes to
        print_all.
    */

    print_all(head);

    free_all(head);

}