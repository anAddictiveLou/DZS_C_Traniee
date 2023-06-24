#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linked_list.h"

List *create_list(void)
{
    return calloc(1, sizeof(List));
}

static void insert_to_list_at_beginning(List *l, int val)
{
    printf("%s %d\n", __func__, __LINE__);
    Node *new_node = NULL;
    new_node = (Node *)calloc(1, sizeof(Node));
    new_node->data = val;

    new_node->next = l->head;
    l->head = new_node;
    new_node = NULL;
    l->size++;
}

static void insert_to_list_at_ending(List *l, int val)
{
    printf("%s %d\n", __func__, __LINE__);
    Node *new_node = NULL;
    new_node = (Node *)calloc(1, sizeof(Node));
    new_node->data = val;

    /* Traverse to last node */
    Node *cur = l->head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = new_node;
    new_node = NULL;
    l->size++;
}

static void insert_to_list_at_ith_position(List *l, int val, int pos)
{
    printf("%s %d\n", __func__, __LINE__);
    Node *new_node = NULL;
    new_node = (Node *)calloc(1, sizeof(Node));
    new_node->data = val;

    /* Go to node ith */
    Node *cur = l->head;
    while (pos - 1 != 0)
    {
        cur = cur->next;
        pos--;
    }

    /* Assign new node to node ith */
    cur->next = new_node;
    new_node = NULL;
    l->size++;
}

void insert_to_list(List *l, int val, int pos)
{

    /* true then go through */
    assert(pos <= l->size + 1 && pos >= 1 && l != NULL);

    if (pos == 1)
    {
        insert_to_list_at_beginning(l, val);
    }
    else if (pos == l->size + 1)
    {
        insert_to_list_at_ending(l, val);
    }
    else
    {
        insert_to_list_at_ith_position(l, val, pos);
    }
}

static void remove_from_list_at_beginning(List *l)
{
    printf("%s %d\n", __func__, __LINE__);

    Node *temp = NULL;
    temp = l->head;
    l->head = l->head->next;
    free(temp);
    temp = NULL;
    l->size--;
}

static void remove_from_list_at_ith_position(List *l, int pos)
{
    printf("%s %d\n", __func__, __LINE__);

    /* Go to (i-1)th node */
    Node *cur = l->head;
    while (pos - 2 != 0)
    {
        cur = cur->next;
        pos--;
    }

    /* Remove ith node */
    Node *temp = NULL;
    temp = cur->next;
    cur->next = cur->next->next;
    free(temp);
    temp = NULL;
    l->size--;
}

static void remove_from_list_at_ending(List *l)
{
    printf("%s %d\n", __func__, __LINE__);

    /* Traverse to pre-last node */
    Node *cur = l->head;
    while (cur->next->next != NULL)
        cur = cur->next;
    free(cur->next);
    cur->next = NULL;
    l->size--;
}

void remove_from_list(List *l, int pos)
{
    /* true then go through */
    assert(pos <= l->size && pos >= 1 && l != NULL && l->size > 0);

    if (pos == 1)
    {
        remove_from_list_at_beginning(l);
    }
    else if (pos == l->size)
    {
        remove_from_list_at_ending(l);
    }
    else
    {
        remove_from_list_at_ith_position(l, pos);
    }
}

void show_list(List *l)
{
    /* assert true go through */
    assert(l != NULL && l->size > 0);

    Node *cur = l->head;
    printf("List has %d elements: ", l->size);
    if (l->size == 1)
    {
        printf("%d", l->head->data);
    }
    else
    {
        while (cur->next != NULL)
        {
            printf("%d ", cur->data);
            cur = cur->next;
        }
        /* Print last node value */
        printf("%d ", cur->data);
    }
    printf("\n");
}

void free_list(List *l)
{
    assert(l != NULL);

    Node *cur = NULL;
    cur = l->head;
    Node *next_node = NULL;

    /* Free each nodes except last node */
    while (cur->next != NULL)
    {
        next_node = cur->next;
        free(cur);
        cur = next_node;
    }

    /* Free last node */
    free(cur);
    cur = NULL;
    next_node = NULL;

    /* Free list */
    free(l);
    l = NULL;
}