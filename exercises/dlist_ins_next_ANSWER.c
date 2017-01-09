#include <stdlib.h>
#include <stdio.h>
#include "dlist.h"

/* ---------------------------- dlist_ins_next --------------------------- */
int dlist_ins_next(DList *list, DListElmt *element, const void *data) {

    DListElmt          *new_element;

    /* Do not allow a NULL element unless the list is empty */
    if (element == NULL && dlist_size(list) != 0)
       return -1;

    /* Allocate storage for the element */
    if ((new_element = (DListElmt *)malloc(sizeof(DListElmt))) == NULL)
       return -1;

    /* Insert the new element into the list */
    new_element->data = (void *)data;

    if (dlist_size(list) == 0) {

       /* Handle insertion when the list is empty */
       list->head = new_element;
       list->head->prev = NULL;
       list->head->next = NULL;
       list->tail = new_element;

    } else {

       /* Handle insertion when the list is not empty */
       new_element->next = element->next;
       new_element->prev = element;

       if (element->next == NULL)
          list->tail = new_element;
       else
          element->next->prev = new_element;

       element->next = new_element;

    }

    /* Adjust the size of the list to account for the inserted element */
    list->size++;

    return 0;

}
