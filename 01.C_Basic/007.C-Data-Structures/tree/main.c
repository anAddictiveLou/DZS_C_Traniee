#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    BST* my_bst = NULL;
    my_bst = create_bst();
    insert_to_bst(my_bst, 10);
    printf("%d\n", my_bst->BSTroot->data);
    insert_to_bst(my_bst, 5);
    printf("%d\n", my_bst->BSTroot->left->data);
    insert_to_bst(my_bst, 2);
    printf("%d\n", my_bst->BSTroot->left->data);
    insert_to_bst(my_bst, 15);
    printf("%d\n", my_bst->BSTroot->right->data);
    insert_to_bst(my_bst, 20);
    printf("%d\n", my_bst->BSTroot->right->right->data);
    insert_to_bst(my_bst, 14);
    printf("%d\n", my_bst->BSTroot->right->left->data);
    printf("%d\n", search_in_bst(my_bst, 10));
    printf("%d\n", search_in_bst(my_bst, 5));
    printf("%d\n", search_in_bst(my_bst, 15));
    printf("%d\n", search_in_bst(my_bst, 20));
    printf("%d\n", search_in_bst(my_bst, 14));
    printf("%d\n", search_in_bst(my_bst, 22));
    printf("%d\n", search_in_bst(my_bst, 14));
    printf("%d\n", get_max_value_in_bst(my_bst));
    printf("%d\n", get_min_value_in_bst(my_bst));
    return 0;
}