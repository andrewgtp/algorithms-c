#include <stdlib.h>
#include "headers.h"


int list_ins_next(List *list, ListElmt *element, const void *data) {

    // here's your new element!
    ListElmt *new_element;

    // alloc mem for new_element
    // TODO: Read up, why need to use ListElmt twice
    if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
        return -1;

    // Insert data into new element 
    // TODO: why do we need (void *) in front? Why do we need to cast to void here
    new_element->data = (void *)data;
/*       
                                           +---------+------+
      new_element:                         | *data   | NULL |
                                           +---------+------+
                                                       next
*/
    // if:
    // Handle insertion somewhere at the head
    // TODO: why not pointer to element?
    if (element == NULL) {
        if (list_size(list) == 0) 
            list->tail = new_element;
        new_element->next = list->head;
        list->head = new_element;     
        
    // else:
    // TODO: lookup list properties
    } else {
    // Handle new_element insertion somewhere other than at the head
        if (element->next == NULL) {
/*               +---------+------+
       element:  |         | NULL |
                 +---------+------+
                             next
*/  
            list->tail = new_element;
/*
// TODO: Add new diagrams showing insertion before the head
    // We have a new element not linked to anything and whos next pointer points to NULL
                                                                      +---------+------+
                                                                      |         | NULL |
                                                                      +---------+------+
                                                                       new_element next
    
    // Here is out list where we want to insert a new element
                 +---------+------+                                   +---------+------+
       list:     |         |   *  |----------------------------------->         |   *  |
                 +---------+------+                                   +---------+------+
                                                                
*/
    }
    // assign new_element next ptr to element next ptr
    new_element->next = element->next;
/*
                                           +---------+------+
 element:                                  |         |   *  +---------------+
                                           +---------+------+               |
                                            new_element next                |
                                                                            |
                                                                            |
                 +---------+---+--+                                   +-----v---+------+
 list:           |         |   *  |----------------------------------->         |   *  |
                 +---------+------+                                   +---------+------+
                   element   next
*/

    // assign element next ptr to new_element
    element->next = new_element;

/*
                                           +---------+------+
 element:                      +----------->         |   *  +---------------+
                               |           +---------+------+               |
                               |            new_element next                |
                               |                                            |
                               |                                            |
                 +---------+---+--+                                   +-----v---+------+
 list:           |         |   *  |                                   |         |   *  |
                 +---------+------+                                   +---------+------+
                   element   next
*/

    }

    /* Adjust the size of the list to account for the inserted element */
    list->size++;    
    return 0;
}

