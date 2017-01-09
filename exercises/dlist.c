#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dlist.h"


/***************************************
*             Helpers                  *
***************************************/
void print_log_header(char *);

/***************************************
*             Prototypes               *
***************************************/
int main();


/*
 * Description: Illustrates using a linked list (see Chapter 5).
 */

const char *LINE = "----------------------------";
const char *LINE_DBL  = "=========================================";


void print_log_header_dbl(char *msg) {
    printf("\n%s\n%s\n%s\n\n", LINE_DBL, msg, LINE_DBL);
}

void print_log_header(char *msg) {
    printf("\n%s\n%s\n%s\n\n", LINE, msg, LINE);
}


static void print_list(const DList *list) {
    DListElmt           *element;
    int                *data, i;

    /* Display the linked list */
    fprintf(stdout, "List size is %d\n", list->size);

    i = 0;
    element = dlist_head(list);

    while (1) {

       data = dlist_data(element);
       fprintf(stdout, "list[%03d]=%03d\n", i, *data);

       i++;

       if (dlist_is_tail(element))
          break;
       else
          element = dlist_next(element);
    }
}

/* --------------------------------- main -------------------------------- */
int main(int argc, char **argv) {

    DList              list;
    DListElmt          *element;

    int                *data,
		       i;

    /* Initialize the doubly-linked list */
    dlist_init(&list, free);

    /* Perform some doubly-linked list operations */
    element = dlist_head(&list);

    for (i = 10; i > 0; i--) {

       if ((data = (int *)malloc(sizeof(int))) == NULL)
	  return 1;

       *data = i;

       if (dlist_ins_prev(&list, dlist_head(&list), data) != 0)
	  return 1;

    }

    print_list(&list);

    element = dlist_head(&list);

    for (i = 0; i < 8; i++)
       element = dlist_next(element);

    data = dlist_data(element);
    fprintf(stdout, "Removing an element after the one containing %03d\n", *data);

    if (dlist_remove(&list, element, (void **)&data) != 0)
       return 1;

    print_list(&list);

    fprintf(stdout, "Inserting 011 at the tail of the list\n");

    *data = 11;
    if (dlist_ins_next(&list, dlist_tail(&list), data) != 0)
       return 1;

    print_list(&list);

    fprintf(stdout, "Removing an element at the tail of the list\n");

    element = dlist_tail(&list);
    if (dlist_remove(&list, element, (void **)&data) != 0)
       return 1;

    print_list(&list);

    fprintf(stdout, "Inserting 012 just before the tail of the list\n");

    *data = 12;
    if (dlist_ins_prev(&list, dlist_tail(&list), data) != 0)
       return 1;

    print_list(&list);

    fprintf(stdout, "Iterating and removing the fourth element\n");

    element = dlist_head(&list);
    element = dlist_next(element);
    element = dlist_prev(element);
    element = dlist_next(element);
    element = dlist_prev(element);
    element = dlist_next(element);
    element = dlist_next(element);
    element = dlist_next(element);

    if (dlist_remove(&list, element, (void **)&data) != 0)
       return 1;

    print_list(&list);

    fprintf(stdout, "Inserting 013 before the first element\n");

    *data = 13;
    if (dlist_ins_prev(&list, dlist_head(&list), data) != 0)
       return 1;

    print_list(&list);

    fprintf(stdout, "Removing an element at the head of the list\n");

    if (dlist_remove(&list, dlist_head(&list), (void **)&data) != 0)
       return 1;

    print_list(&list);

    fprintf(stdout, "Inserting 014 just after the head of the list\n");
    *data = 14;

    if (dlist_ins_next(&list, dlist_head(&list), data) != 0)
       return 1;

    print_list(&list);

    fprintf(stdout, "Inserting 015 two elements after the head of the list\n");

    if ((data = (int *)malloc(sizeof(int))) == NULL)
       return 1;

    *data = 15;
    element = dlist_head(&list);
    element = dlist_next(element);

    if (dlist_ins_next(&list, element, data) != 0)
       return 1;

    print_list(&list);

    i = dlist_is_head(dlist_head(&list));
    fprintf(stdout, "Testing dlist_is_head...Value=%d (1=OK)\n", i);
    i = dlist_is_head(dlist_tail(&list));
    fprintf(stdout, "Testing dlist_is_head...Value=%d (0=OK)\n", i);
    i = dlist_is_tail(dlist_tail(&list));
    fprintf(stdout, "Testing dlist_is_tail...Value=%d (1=OK)\n", i);
    i = dlist_is_tail(dlist_head(&list));
    fprintf(stdout, "Testing dlist_is_tail...Value=%d (0=OK)\n", i);

    /* Destroy the doubly-linked list */
    fprintf(stdout, "Destroying the list\n");
    dlist_destroy(&list);

    return 0;

}

/* ------------------------------ dlist_init ----------------------------- */
void dlist_init(DList *list, void (*destroy)(void *data)) {

    /* Initialize the list */
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

}


/* ---------------------------- dlist_destroy ---------------------------- */
void dlist_destroy(DList *list) {

    void               *data;

    /* Remove each element */
    while (dlist_size(list) > 0) {

       if (dlist_remove(list, dlist_tail(list), (void **)&data) == 0 && list->
	  destroy != NULL) {

	  /* Call a user-defined function to free dynamically allocated data */
	  list->destroy(data);

       }

    }

    /* No operations are allowed now, but clear the structure as a precaution */
    memset(list, 0, sizeof(DList));

}


/* ---------------------------- dlist_ins_next --------------------------- */

// SOURCE IN: LIST_INS_NEXT_ANSWER.C

/* ---------------------------- dlist_ins_prev --------------------------- */
int dlist_ins_prev(DList *list, DListElmt *element, const void *data) {

    DListElmt          *new_element;

    /* Do not allow a NULL element unless the list is empty */
    if (element == NULL && dlist_size(list) != 0)
       return -1;

    /* Allocate storage to be managed by the abstract data type */
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
       new_element->next = element; 
       new_element->prev = element->prev;

       if (element->prev == NULL)
	  list->head = new_element;
       else
	  element->prev->next = new_element;

       element->prev = new_element;

    }


    /* Adjust the size of the list to account for the new element */
    list->size++;

    return 0;

}


/* ----------------------------- dlist_remove ---------------------------- */
int dlist_remove(DList *list, DListElmt *element, void **data) {

    /* Do not allow a NULL element or removal from an empty list */
    if (element == NULL || dlist_size(list) == 0)
       return -1;

    /* Remove the element from the list */
    *data = element->data;

    if (element == list->head) {

       /* Handle removal from the head of the list */
       list->head = element->next;

       if (list->head == NULL)
	  list->tail = NULL;
       else
	  element->next->prev = NULL;

    } else {

       /* Handle removal from other than the head of the list */
       element->prev->next = element->next;

       if (element->next == NULL)
	  list->tail = element->prev;
       else
	  element->next->prev = element->prev;

    }

    /* Free the storage allocated by the abstract data type */
    free(element);

    /* Adjust the size of the list to account for the removed element */
    list->size--;

    return 0;

}
