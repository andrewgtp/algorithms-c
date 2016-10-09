#include <stdlib.h>
#include "headers.h"


int list_ins_next(List *list, ListElmt *element, const void *data) {

    ListElmt *new_element;

    if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
        return -1;

    new_element->data = (void *)data;

    if (element == NULL) {
        if (list_size(list) == 0) 
            list->tail = new_element;

        new_element->next = list->head;
        list->head = new_element;     

        
    } else {
        if (element->next == NULL) {
            printf("TAIL INSERT NOW!!!!\n");
            list->tail = new_element;
	}

	new_element->next = element->next;
	element->next = new_element;
    }

    list->size++;    
    return 0;
}



















