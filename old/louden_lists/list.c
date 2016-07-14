#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct ListElmt_ {
  void *data;
  struct ListElmt_ *next;
} ListElmt;

typedef struct List_ {
  int size;
  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);
  ListElmt  *head;
  ListElmt  *tail;
} List;


/***********************
 * PUBLIC INTERFACE 
 ***********************/
void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
int list_ins_next(List *list, ListElmt *element, const void *data);
int list_rem_next(List *list, ListElmt *element, void **data);

#define list_size(list) ((list)->size)
#endif


int main() {
   //List *list;
   List list;
   void *data;
   int max_size;

   printf("Prepare to list_init!\n");

   //list_init(list, void (*destroy)(void *data));
   //list_init(list, NULL);
   list_init(&list, NULL);
   printf("list_init DONE\n");
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
    return;
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

// int list_ins_next

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

    free(old_element);
    // adjust size of the list to account for removed element
    list->size--;

    return 0;
}


