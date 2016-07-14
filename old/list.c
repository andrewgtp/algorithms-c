
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "list.h"


void list_print(List *list){
    ListElmt *current = list->head;

    if (current != NULL) {
        while(current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }   
        printf("\n\n");
    } else {
        printf("EMPTY!\n\n");
    }   
}

// initialize a list
/*
Set *convering;
void set_init(Set *set, void (*destroy)(void *data)) {
*/
void list_init(List *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
    //return;
}

void list_destroy(List *list) {
    void *data;

    // remove each element
    while (list_size(list) > 0) {
        if (list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL) {
            // call a user-defined function to free dynamically allocated data.
            list->destroy(data);
        }
    }
}

int list_ins_next(List *list, ListElmt *element, const void *data) {
    ListElmt *new_element;

    // allocate storage for the element
    if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
        return -1;

    // insert the element into the list
    new_element->data = (void *)data;
    printf("new_element (addr): %p\n", &new_element);
    printf("new_element->data: %d\n", new_element->data);

    if (element == NULL) {
        // handle insertion at head of the list
        if (list_size(list) == 0)
            printf("inserting - head of list\n");
            list->tail = new_element;
            //printf("list->tail->data: %d\n", list->tail->data);

        new_element->next = list->head;
        list->head = new_element;
    } else {
        // handle insertion at other than head of list
        printf("inserting - other than head of list\n");
        if (element->next == NULL)
            list->tail = new_element;
        new_element->next = element->next;
        element->next = new_element;
        printf("list->tail->next: %p\n", list->tail->next);
    }
    
    printf("element (addr): %p\n", &element);
    // adjust size of list to account for inserted element
    list->size++;
    printf("list->size: %d\n", list->size);
    //printf("list->head->data: %d\n", list->head->data);

    return 0;
}

int list_rem_next(List *list, ListElmt *element, void **data) {
    ListElmt *old_element;

    // do not allow removal from empty list
    if (list_size(list) == 0)
        return -1;

    // remove element from list
    if (element == NULL) {
        // handle removal of head element
        *data = list->head->data;
        old_element = list->head;
        list->head = list->head->next;
        if (list_size(list) == 0)
            list->tail = NULL;
    } else {
        // handle removal of non-head element
        if (element->next == NULL)
            return -1;
        *data = element->next->data;
        old_element = element->next;
        element->next = element->next->next;
        if (element->next == NULL)
            list->tail = element;
    }

    ListElmt *current = list->head;
    while(current != 0)
    {   
        printf("%d\n", current->data);
        current= current->next;
    }

    free(old_element);
    // adjust size of the list to account for removed element
    list->size--;

    return 0;
}
