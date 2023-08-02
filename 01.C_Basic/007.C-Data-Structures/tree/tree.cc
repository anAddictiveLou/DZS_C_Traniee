#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;

#include "tree.h"
#include "queue.h"


static BSTNode* _create_bstNode(void)
{
    return (BSTNode*)calloc(1, sizeof(BSTNode));
}

static void _insert_to_bst_root_node(BSTNode **bst_root, int val)
{
    *bst_root = _create_bstNode();
    (*bst_root)->data = val;
}

static void _insert_to_bst_except_root(BSTNode *bst_root, int val)
{

    if (val < bst_root->data)
    {
        if (NULL == bst_root->left) 
        {
            bst_root->left = _create_bstNode();
            bst_root->left->data = val;
            return;
        }
        _insert_to_bst_except_root(bst_root->left, val);
    }
    else if (val > bst_root->data)
    {
        if (NULL == bst_root->right) 
        {
            bst_root->right = _create_bstNode();
            bst_root->right->data = val;
            return;
        }
        _insert_to_bst_except_root(bst_root->right, val);
    }
}

static bool _search_in_bst_using_bst_root(BSTNode* bst_root, int val)
{

    if (NULL == bst_root)
        return false;

    if (val == bst_root->data) {
        return true;
    }
    else if (val < bst_root->data) 
    {
        return _search_in_bst_using_bst_root(bst_root->left, val);
    }
    else
    {
        return _search_in_bst_using_bst_root(bst_root->right, val);
    }
}

static int _get_max_value_in_bst_using_bst_root(BSTNode* bst_root)
{
    if (bst_root->right == NULL)
        return bst_root->data;
    return _get_max_value_in_bst_using_bst_root(bst_root->right);
}

static int _get_min_value_in_bst_using_bst_root(BSTNode* bst_root)
{
    if (bst_root->left == NULL) 
        return bst_root->data;
    return _get_min_value_in_bst_using_bst_root(bst_root->left);
}

static void _show_bst(BSTNode* bst_root)
{
    if (bst_root == NULL)
        return;
    printf("%d  ", bst_root->data);
    _show_bst(bst_root->left);
    _show_bst(bst_root->right);
}

static void _show_bst_using_level_order_strategy(BSTNode* bst_root, CircularQueue* q)
{
    if (NULL == bst_root)
        return;

    BSTNode* temp = NULL;

    enqueue(q, (void*)bst_root);
    while (true != isEmpty(q))
    {
        temp = (BSTNode*) dequeue(q);
        printf("%d ", temp->data);
        if (NULL != temp->left) 
            enqueue(q, (void*) temp->left);
        if (NULL != temp->right)
            enqueue(q, (void*) temp->right);    
    }
    
}

BST* create_bst(void)
{
    return (BST*)calloc(1, sizeof(BST));
}

void insert_to_bst(BST *bst, int val)
{

    assert(bst != NULL && "Create a bst first");

    if (NULL == bst->BSTroot)
    {
        _insert_to_bst_root_node(&bst->BSTroot, val);
    }
    else
    {
        _insert_to_bst_except_root(bst->BSTroot, val);
    }
}

bool search_in_bst(BST* bst, int val)
{
    assert(bst != NULL && "Create a bst first");
    return _search_in_bst_using_bst_root(bst->BSTroot, val);
}

int get_max_value_in_bst(BST* bst)
{
    assert(NULL != bst && "Create a bst first");
    return _get_max_value_in_bst_using_bst_root(bst->BSTroot);
}

int get_min_value_in_bst(BST* bst)
{
    assert(NULL != bst && "Create a bst first");
    return _get_min_value_in_bst_using_bst_root(bst->BSTroot);
}

static void _remove_from_bst(BSTNode** bst_node, int val)
{
    BSTNode* temp = NULL;
    if (NULL == (*bst_node)) 
    {
        return;
    }

    if (val < (*bst_node)->data)
    {
        _remove_from_bst(&((*bst_node)->left), val);
    }
    else if (val > (*bst_node)->data)
    {
        _remove_from_bst(&((*bst_node)->right), val);
    }
    /* Found node to remove */
    else if (val == (*bst_node)->data)
    {
        /* case 1: node is leaf node */
        if ((*bst_node)->right == NULL && (*bst_node)->left == NULL)
        {
            free((*bst_node));
            (*bst_node) = NULL;
            return;
        }
        /* case 2: node has one child */
        else if ((*bst_node)->left == NULL) 
        {
            temp = (*bst_node);
            (*bst_node) = (*bst_node)->right;
            free(temp);
            temp = NULL;
            return;
        }
        else if ((*bst_node)->right == NULL)
        {
            temp = (*bst_node);
            (*bst_node) = (*bst_node)->left;
            free(temp);
            temp = NULL;
            return;
        }

        /* case 3: node has two child */
        else 
        {
            (*bst_node)->data = _get_min_value_in_bst_using_bst_root((*bst_node)->right);
            _remove_from_bst(&((*bst_node)->right), (*bst_node)->data);
        }
    }
    return;
    
}

void remove_from_bst(BST* bst, int val)
{
    assert(NULL != bst && "Create a bst first");
    _remove_from_bst(&(bst->BSTroot), val);
}

void show_bst(BST* bst)
{
    assert(NULL != bst && "Create a bst first");
    _show_bst(bst->BSTroot);
    printf("\n");
}

void show_bst_using_level_order_strategy(BST* bst)
{
    CircularQueue q;
    initializeQueue(&q);
    assert(NULL != bst && "Create a bst first");
    _show_bst_using_level_order_strategy(bst->BSTroot, &q);
    free(q.data);
}

void print_BST(BSTNode* root, int isRight, int offset) 
{
    if (root == NULL)
        return;

    offset += 7;

    print_BST(root->right, 1, offset);

    for (int i = 7; i < offset; i++)
        printf(" ");

    if (isRight) {
        printf(" /");
    } else {
        printf(" \\");
    }

    printf("----- ");
    printf("%d\n", root->data);

    print_BST(root->left, 0, offset);
}

void static _free_bst(BSTNode* bst_root)
{
    if (NULL == bst_root)
        return;
    
    /* Free left subtree */
    _free_bst(bst_root->left);

    /* Free right subtree */
    _free_bst(bst_root->right);

    /* Free current node */
    free(bst_root);
}

void free_bst(BST* bst)
{
    _free_bst(bst->BSTroot);
    free(bst);
}




static void _top_view(BSTNode* bst_root)
{
    if (!bst_root)
        return;
    map<int, int> Map;
    queue<std::pair<BSTNode*, int>> Que;
    Que.push({bst_root, 0});
    
    while (!Que.empty())
    {
        pair<BSTNode*, int> elm = Que.front();
        Que.pop();
        BSTNode* node = elm.first;
        int dis = elm.second;

        if (Map.find(dis) == Map.end()) 
            Map[dis] = node->data;
        
        if (NULL != node->left)
            Que.push({bst_root->left, dis-1});
        
        if (NULL != node->right)
            Que.push({bst_root->right, dis+1});

        for (const auto el : Map)
            cout << el.second << " ";
    }
}

void top_view(BST* bst)
{
    _top_view(bst->BSTroot);
}