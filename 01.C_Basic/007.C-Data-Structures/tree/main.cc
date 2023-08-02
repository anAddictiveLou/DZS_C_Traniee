#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <time.h>

#define MAX_NODE 15
#define RAND_MAX_VAL 50

int main()
{
    system("clear");
    srand(time(NULL));

    /* Step 1 */
    BST *my_bst = create_bst();
    for (int i = 1; i <= MAX_NODE; i++)
    {
        insert_to_bst(my_bst, rand() % RAND_MAX_VAL);
    }
    printf("\nStep 1: Initialization of BST:\n\n\n\n\n");
    print_BST(my_bst->BSTroot, 4, 0);
    free_bst(my_bst);
    my_bst = NULL;
    
    // /* Step 2 */
    // printf("\n\nStep 2: Max key: %d\n", get_max_value_in_bst(my_bst));
    // printf("        Min key: %d\n", get_min_value_in_bst(my_bst));

    // /* Step 3 */
    // printf("\nStep 3: Keys are divisible by 3 in BST:");
    // for (int i = 3; i <= RAND_MAX_VAL; i+=3)
    // {
    //     if (true == search_in_bst(my_bst, i))
    //         printf("%d ", i);
    // }
    // printf("\n");

    // /* Step 4 */
    // for (int i = 2; i <= RAND_MAX_VAL; i+=2)
    // {
    //     remove_from_bst(my_bst, i);
    // }

    // printf("\n\n\n\nStep 4: BST after removing key that be divisible by 2: \n\n\n\n\n\n");
    // print_BST(my_bst->BSTroot, 4, 0);
    // my_bst = NULL;
    return 0;
}