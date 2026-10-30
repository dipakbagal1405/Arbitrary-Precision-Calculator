#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

Node* list1 = NULL;
Node* list2 = NULL;
Node* res_list = NULL;
char operator;

void insert_at_last(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void slicing_input_dll(char* argv[]) {
    char* ptr1 = argv[1];
    if (*ptr1 == '+' || *ptr1 == '-') 
       ptr1++;
    while (*ptr1 != '\0') {
        insert_at_last(&list1, *ptr1 - '0');
        ptr1++;
    }

    char* ptr2 = argv[3];
    if (*ptr2 == '+' || *ptr2 == '-') ptr2++;
    while (*ptr2 != '\0') {
        insert_at_last(&list2, *ptr2 - '0');
        ptr2++;
    }

    operator = argv[2][0];
}

void print_list(Node* head) {
    Node* temp = head;

    while (temp != NULL && temp->data == 0 && temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

