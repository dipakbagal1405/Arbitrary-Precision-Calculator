#ifndef APC_H
#define APC_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

extern Node* list1;
extern Node* list2;
extern Node* res_list;
extern char operator;

int is_valid_number(const char* str);
int validate_Number_of_CLA(int argc);
void validate_input(char* argv[]);

void insert_at_last(Node** head, int data);
void slicing_input_dll(char* argv[]);
void print_list(Node* head);

void addition(Node* l1, Node* l2, Node** res);
int compare_lists(Node* l1, Node* l2);
void subtraction(Node* l1, Node* l2, Node** res);
void multiplication(Node* l1, Node* l2, Node** res);
void division(Node* l1, Node* l2, Node** res);

#endif
