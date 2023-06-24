#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} List;

List* create_list(void);
void insert_to_list(List* l, int val, int pos);
void show_list(List* l);
void remove_from_list(List* l, int pos);
void free_list(List* l);

#endif