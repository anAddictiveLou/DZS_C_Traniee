#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>

#include "linked_list.h"

int main()
{
    List* pNum_list = NULL;
    pNum_list = create_list();
    insert_to_list(pNum_list, 2, 1);
    insert_to_list(pNum_list, 3, 1);
    insert_to_list(pNum_list, 4, 2);
    show_list(pNum_list);  
    remove_from_list(pNum_list, pNum_list->size);
    remove_from_list(pNum_list, 2);
    show_list(pNum_list);   
    free_list(pNum_list);
    return 0;
}