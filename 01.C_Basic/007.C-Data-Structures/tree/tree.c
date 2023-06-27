#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tree.h"

BST* create_bst(void)
{
    printf("%s %d\n", __func__, __LINE__);
    BST *new_bst = (BST *)calloc(1, sizeof(BST));
    new_bst->height = -1;
    return new_bst;
}

static BSTNode* create_bstNode(void)
{
    printf("%s %d\n", __func__, __LINE__);
    return calloc(1, sizeof(BSTNode));
}

static void insert_to_bst_root_node(BSTNode **bst_root, int val)
{
    printf("%s %d\n", __func__, __LINE__);
    *bst_root = create_bstNode();
    (*bst_root)->data = val;
}

static void insert_to_bst_except_root(BSTNode *bst_root, int val)
{
    printf("%s %d\n", __func__, __LINE__);
    if (val <= bst_root->data)
    {
        if (bst_root->left == NULL)
        {
            bst_root->left = create_bstNode();
            bst_root->left->data = val;
            return;
        }
        insert_to_bst_except_root(bst_root->left, val);
    }
    else
    {
        if (bst_root->right == NULL)
        {
            bst_root->right = create_bstNode();
            bst_root->right->data = val;
            return;
        }
        insert_to_bst_except_root(bst_root->right, val);
    }
}

void insert_to_bst(BST *bst, int val)
{

    printf("%s %d\n", __func__, __LINE__);
    /* true then go through */
    assert(bst != NULL);

    if (bst->BSTroot == NULL)
    {
        insert_to_bst_root_node(&bst->BSTroot, val);
        bst->height = 0;
    }
    else
    {
        insert_to_bst_except_root(bst->BSTroot, val);
        bst->height++;
    }
}

static bool search_in_bst_using_bst_root(BSTNode* bst_root, int val)
{
    bool ret = false;
    printf("%s %d\n", __func__, __LINE__);

    if (val < bst_root->data) 
    {
        if (bst_root->left == NULL)
            return false; 
        return search_in_bst_using_bst_root(bst_root->left, val);
    }
    else if (val > bst_root->data)
    {
        if (bst_root->right == NULL)
            return false; 
        return search_in_bst_using_bst_root(bst_root->right, val);
    }
    else if (val == bst_root->data)
        return true;
}

bool search_in_bst(BST* bst, int val)
{
    printf("%s %d\n", __func__, __LINE__);
    if (bst->height == -1) 
        return false;
    return search_in_bst_using_bst_root(bst->BSTroot, val);
}

static int get_max_value_in_bst_using_bst_root(BSTNode* bst_root)
{
    if (bst_root->right == NULL)
        return bst_root->data;
    return get_max_value_in_bst_using_bst_root(bst_root->right);
}

int get_max_value_in_bst(BST* bst)
{
    assert(bst->height != -1);

    return get_max_value_in_bst_using_bst_root(bst->BSTroot);
}

static int get_min_value_in_bst_using_bst_root(BSTNode* bst_root)
{
    if (bst_root->left == NULL)
        return bst_root->data;
    return get_min_value_in_bst_using_bst_root(bst_root->left);
}

int get_min_value_in_bst(BST* bst)
{
    assert(bst->height != -1);

    return get_min_value_in_bst_using_bst_root(bst->BSTroot);
}

int get_height_of_bst(BST* bst)
{
    if ()
}