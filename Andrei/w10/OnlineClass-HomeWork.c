#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int age;
    float height;
} person;

typedef struct node {
    person p;
    struct node* next;
} node;

node* create_node(char* name, int age, float height) {
    node* n = malloc(sizeof(node));
    if (!n) exit(1);
    strcpy(n->p.name, name);
    n->p.age = age;
    n->p.height = height;
    n->next = NULL;
    return n;
}

void add_node_sorted(node** head, char* name, int age, float height) {
    node* n = create_node(name, age, height);
    if (*head == NULL || age > (*head)->p.age) {
        n->next = *head;
        *head = n;
        return;
    }
    node* cur = *head;
    while (cur->next && cur->next->p.age > age)
        cur = cur->next;
    n->next = cur->next;
    cur->next = n;
}

void print_all(node* h) {
    int i = 0;
    while (h) {
        printf("person #%d: Name: %s, Age: %d, Height: %.1f\n", i, h->p.name, h->p.age, h->p.height);
        h = h->next;
        i++;
    }
}

void free_all(node* h) {
    node* tmp;
    while (h) {
        tmp = h;
        h = h->next;
        free(tmp);
    }
}

int main() {
    node* head = NULL;
    add_node_sorted(&head, "Gaiya", 29, 5.4);
    add_node_sorted(&head, "shehara", 24, 5.0);
    add_node_sorted(&head, "Mert", 21, 5.7);
    add_node_sorted(&head, "Melisa", 30, 5.6);
    add_node_sorted(&head, "Inci", 27, 5.3);

    add_node_sorted(&head, "Inci", 28, 5.3);
    add_node_sorted(&head, "Andrei", 20, 5.3);
    

    print_all(head);
    free_all(head);
}
