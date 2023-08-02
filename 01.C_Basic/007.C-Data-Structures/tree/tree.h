#ifndef _TREE_H
#define _TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BSTNode{
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

typedef struct {
    BSTNode* BSTroot;
} BST;

BST* create_bst(void);
void insert_to_bst(BST* bst, int val);
void remove_from_bst(BST* bst, int val);
bool search_in_bst(BST* bst, int val);
int get_max_value_in_bst(BST* bst);
int get_min_value_in_bst(BST* bst);
void show_bst(BST* bst);
void show_bst_using_level_order_strategy(BST* bst);
void print_BST(struct BSTNode* root, int isRight, int offset);
void free_bst(BST* bst);

void top_view(BST* bst);

#endif