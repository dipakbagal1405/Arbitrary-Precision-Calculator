#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

void addition(Node* l1, Node* l2, Node** res) {
    Node* t1 = l1;
    Node* t2 = l2;
    while (t1 && t1->next){
        t1 = t1->next;
    }
    while (t2 && t2->next){
        t2 = t2->next;
    }

    int carry = 0;
    Node* head = NULL;

    while (t1 || t2 || carry) {
        int sum = carry;
        if (t1) {
            sum += t1->data;
            t1 = t1->prev;
        }
        if (t2) {
            sum += t2->data;
            t2 = t2->prev;
        }
        carry = sum / 10;
        
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = sum % 10;
        new_node->prev = NULL;
        new_node->next = head;
        if (head){ 
         head->prev = new_node;
        }
        head = new_node;
    }
    *res = head;
}

void subtraction(Node* l1, Node* l2, Node** res) {
    Node* t1 = l1;
    Node* t2 = l2;
    while (t1 && t1->next) 
         t1 = t1->next;
    while (t2 && t2->next) 
         t2 = t2->next;

    int borrow = 0;
    Node* head = NULL;

    while (t1 || t2) {
        int diff = borrow;
        if (t1) {
            diff += t1->data;
            t1 = t1->prev;
        }
        if (t2) {
            diff -= t2->data;
            t2 = t2->prev;
        }

        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }

        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = diff;
        new_node->prev = NULL;
        new_node->next = head;
        if (head) 
            head->prev = new_node;
        head = new_node;
    }
    *res = head;
}
int compare_lists(Node* l1, Node* l2) {
    int len1 = 0, len2 = 0;
    Node* t1 = l1;
    Node* t2 = l2;

    while (t1) 
    { 
        len1++; 
        t1 = t1->next; 
    }
    while (t2) 
    { 
        len2++; 
        t2 = t2->next; 
    }

    if (len1 > len2) 
    return 1;
    if (len2 > len1) 
    return -1;

    t1 = l1;
    t2 = l2;
    while (t1 && t2) {
        if (t1->data > t2->data) 
        return 1;
        if (t2->data > t1->data) 
        return -1;
        t1 = t1->next;
        t2 = t2->next;
    }
    return 0;
}
void multiplication(Node* l1, Node* l2, Node** res) {
    Node* t2 = l2;
    while (t2 && t2->next) {
        t2 = t2->next;
    }

    int shift = 0;
    Node* final_res = NULL;

    while (t2) {
        Node* t1 = l1;
        while (t1 && t1->next) {
            t1 = t1->next;
        }

        int carry = 0;
        Node* current_res = NULL;

        for (int i = 0; i < shift; i++) {
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->data = 0;
            new_node->prev = NULL;
            new_node->next = current_res;
            if (current_res) {
                current_res->prev = new_node;
            }
            current_res = new_node;
        }

        while (t1 || carry) {
            int prod = carry;
            if (t1) {
                prod += (t1->data * t2->data);
                t1 = t1->prev;
            }
            carry = prod / 10;
            
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->data = prod % 10;
            new_node->prev = NULL;
            new_node->next = current_res;
            if (current_res) {
                current_res->prev = new_node;
            }
            current_res = new_node;
        }

        if (final_res == NULL) {
            final_res = current_res;
        } else {
            Node* temp_res = NULL;
            addition(final_res, current_res, &temp_res);
            final_res = temp_res;
        }

        shift++;
        t2 = t2->prev;
    }
    *res = final_res;
}
void division(Node* l1, Node* l2, Node** res) {
    if (l2 == NULL || (l2->data == 0 && l2->next == NULL)) {
        printf("Result: Error (Division by Zero)\n");
        *res = NULL;
        return;
    }

    int cmp = compare_lists(l1, l2);
    if (cmp == -1) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = 0;
        new_node->prev = NULL;
        new_node->next = NULL;
        *res = new_node;
        return;
    } else if (cmp == 0) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = 1;
        new_node->prev = NULL;
        new_node->next = NULL;
        *res = new_node;
        return;
    }

    Node* count_list = NULL;
    Node* one_node = (Node*)malloc(sizeof(Node));
    one_node->data = 1;
    one_node->prev = NULL;
    one_node->next = NULL;

    Node* temp_l1 = l1;

    while (compare_lists(temp_l1, l2) >= 0) {
        Node* sub_res = NULL;
        subtraction(temp_l1, l2, &sub_res);
        temp_l1 = sub_res;

        while (temp_l1 != NULL && temp_l1->data == 0 && temp_l1->next != NULL) {
            Node* old = temp_l1;
            temp_l1 = temp_l1->next;
            if (temp_l1) temp_l1->prev = NULL;
            free(old);
        }

        if (count_list == NULL) {
            count_list = (Node*)malloc(sizeof(Node));
            count_list->data = 1;
            count_list->prev = NULL;
            count_list->next = NULL;
        } else {
            Node* add_res = NULL;
            addition(count_list, one_node, &add_res);
            count_list = add_res;
        }
    }
    *res = count_list;
}
