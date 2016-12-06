#include <stdlib.h>
#include "headers.h"


/* ----------------------------- list_rem_next --------------------------- */
int list_rem_next(List *list, ListElmt *element, void **data) {

    ListElmt           *old_element;

    /* Do not allow removal from an empty list */
    if (list_size(list) == 0)
       return -1;

    /* Remove the element from the list */
    if (element == NULL) {

       /* Handle removal from the head of the list */

       // cache the data temporarily
       *data = list->head->data;
       // NOTE: we need to store address of head so we can free that memory later
       //       otherwise that memory address will be lost on next assignment
       old_element = list->head;
       list->head = list->head->next;

       if (list_size(list) == 1)
	  list->tail = NULL;

    } else {

       /* Handle removal from somewhere other than the head */
       if (element->next == NULL)
	  return -1;

       // cache the data temporarily
       *data = element->next->data;
       
       // NOTE: we need to store address of head so we can free that memory later
       //       otherwise that memory address will be lost on next assignment
       old_element = element->next;
       element->next = element->next->next;

       if (element->next == NULL)
	  list->tail = element;

    }
    /* Free the storage allocated by the abstract data type */
    free(old_element);


    /* Adjust the size of the list to account for the removed element */
    list->size--;

    return 0;

}


/*
// Here is a list from which we want to remove a specified element
// We could remove it from one of 2 places:

// [A]. remove from HEAD 
// [B]. remove from somewhere other than HEAD 

// Lastly:
// Free the storage allocated by the abstract data type
// Adjust the size of the list to account for the removed element


// ====================================================================================================== 
// BEFORE OPERATION
// ====================================================================================================== 

            +---------+---+--+     +---------+------+     +---------+------+     +---------+------+
list:       |         |   *  +----->         |   *  +----->         |   *  +----->         |   *  |
            +---------+---+--+     +---------+------+     +---------+------+     +---------+------+
              element   next         element   next         element   next         element   next

             ^^^^^ HEAD ^^^^^                                                     ^^^^^ TAIL ^^^^^ 

// ====================================================================================================== 
// SCENARIO A: remove from HEAD 
// ====================================================================================================== 

            +---------+------+             
old:        |         |   *  +-----------+              
            +---------+------+           |    
              element   next             |
                                   +-----v---+------+     +---------+------+     +---------+------+
list:                              |         |   *  +----->         |   *  +----->         |   *  |
                                   +---------+------+     +---------+------+     +---------+------+
                                     element   next         element   next         element   next

             ^^^^^ HEAD ^^^^^                                                     ^^^^^ TAIL ^^^^^ 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            +---------+------+             
old:        |         |   *  +
            +---------+------+
                old_element
                                   +---------+------+     +---------+------+     +---------+------+
list:                              |         |   *  +----->         |   *  +----->         |   *  |
                                   +---------+------+     +---------+------+     +---------+------+
                                     element   next         element   next         element   next

             ^^^^^ HEAD ^^^^^                                                     ^^^^^ TAIL ^^^^^ 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                          
            +---------+------+     +---------+------+     +---------+------+
list:       |         |   *  +----->         |   *  +----->         |   *  |
            +---------+------+     +---------+------+     +---------+------+
              element   next         element   next         element   next


             ^^^^^ HEAD ^^^^^                              ^^^^^ TAIL ^^^^^ 


// ====================================================================================================== 
// SCENARIO B: remove from somewhere other than HEAD 
// ====================================================================================================== 

                                                          +---------+------+
old:                                             +-------->         |   *  +-----------+
                                                 |        +---------+------+           |
                                                 |          element   next             |
            +---------+------+     +---------+---+--+                            +-----v---+------+
list:       |         |   *  +----->         |   *  +                            |         |   *  |
            +---------+---+--+     +---------+------+                            +---------+------+
              element   next         element   next                                element   next

             ^^^^^ HEAD ^^^^^                                                     ^^^^^ TAIL ^^^^^ 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                                                          +---------+------+
old:                                                      |         |   *  |
                                                          +---------+------+
                                                              old_element 
            +---------+------+     +---------+------+                            +---------+------+
list:       |         |   *  +----->         |   *  +---------------------------->         |   *  |
            +---------+---+--+     +---------+------+                            +---------+------+
              element   next         element   next                                element   next

             ^^^^^ HEAD ^^^^^                                                     ^^^^^ TAIL ^^^^^ 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            +---------+------+     +---------+------+     +---------+------+
list:       |         |   *  +----->         |   *  +----->         |   *  |
            +---------+---+--+     +---------+------+     +---------+------+
              element   next         element   next         element   next

             ^^^^^ HEAD ^^^^^                              ^^^^^ TAIL ^^^^^ 

*/
