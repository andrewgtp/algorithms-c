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
       *data = list->head->data;
       old_element = list->head;
       list->head = list->head->next;

       if (list_size(list) == 1)
	  list->tail = NULL;

    } else {

       /* Handle removal from somewhere other than the head */
       if (element->next == NULL)
	  return -1;

       *data = element->next->data;
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
