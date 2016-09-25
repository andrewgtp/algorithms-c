#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "headers.h"


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

void print_log_header(char *msg) {
    printf("\n%s\n%s\n%s\n\n", LINE, msg, LINE);
}


static void print_list(const List *list) {
    ListElmt           *element;
    int                *data, i;

    /* Display the linked list */
    fprintf(stdout, "List size is %d\n", list_size(list));

    i = 0;
    element = list_head(list);

    while (1) {

       data = list_data(element);
       fprintf(stdout, "list[%03d]=%03d\n", i, *data);

       i++;

       if (list_is_tail(element))
	  break;
       else
	  element = list_next(element);
    }
    return;
}


int main(int argc, char **argv) {

    List               list;
    ListElmt           *element;
    int                *data, i, is_not_empty;

    print_log_header("DATA STRUCTURES: LISTS");

    list_init(&list, free);


    /***********************************************/
    print_log_header("EXAMPLE #1");
    /***********************************************/

    element = list_head(&list);

    for (i = 10; i > 0; i--) {

        data = (int *)malloc(sizeof(int));
        if (data == NULL)
            return 1;

        *data = i;

        is_not_empty = list_ins_next(&list, NULL, data); 
	if (is_not_empty != 0)
	  return 1;
    }

    print_list(&list);

    /***********************************************/
    print_log_header("EXAMPLE #2");
    /***********************************************/

    element = list_head(&list);

    for (i = 0; i < 7; i++)
       element = list_next(element);

    data = list_data(element);
    fprintf(stdout, "Removing an element after the one containing %03d\n", *data);

    is_not_empty = list_rem_next(&list, element, (void **)&data);
    if (is_not_empty != 0)
       return 1;

    print_list(&list);

    /***********************************************/
    print_log_header("EXAMPLE #3");
    /***********************************************/

    fprintf(stdout, "Inserting 011 at the tail of the list\n");

    *data = 11;
    is_not_empty =  list_ins_next(&list, list_tail(&list), data);
    if (is_not_empty != 0)
       return 1;

    print_list(&list);

    fprintf(stdout, "Removing an element after the first element\n");

    /***********************************************/
    print_log_header("EXAMPLE #4");
    /***********************************************/

    element = list_head(&list);
    is_not_empty = list_rem_next(&list, element, (void **)&data);
    if (is_not_empty != 0)
       return 1;

    print_list(&list);

    /***********************************************/
    print_log_header("EXAMPLE #5");
    /***********************************************/

    fprintf(stdout, "Inserting 012 at the head of the list\n");

    *data = 12;
    is_not_empty = list_ins_next(&list, NULL, data);
    if (is_not_empty != 0)
       return 1;

    print_list(&list);

    /***********************************************/
    print_log_header("EXAMPLE #6");
    /***********************************************/

    fprintf(stdout, "Iterating and removing the fourth element\n");

    element = list_head(&list);
    element = list_next(element);
    element = list_next(element);

    is_not_empty = list_rem_next(&list, element, (void **)&data);
    if (is_not_empty != 0)
       return 1;

    print_list(&list);

    /***********************************************/
    print_log_header("EXAMPLE #7");
    /***********************************************/

    fprintf(stdout, "Inserting 013 after the first element\n");

    *data = 13;
    is_not_empty =  list_ins_next(&list, list_tail(&list), data);
    if (is_not_empty != 0)
       return 1;

    print_list(&list);

    /***********************************************/
    print_log_header("EXAMPLE #8");
    /***********************************************/

    i = list_is_head(&list, list_head(&list));
    fprintf(stdout, "Testing list_is_head...Value=%d (1=OK)\n", i);
    i = list_is_head(&list, list_tail(&list));
    fprintf(stdout, "Testing list_is_head...Value=%d (0=OK)\n", i);
    i = list_is_tail(list_tail(&list));
    fprintf(stdout, "Testing list_is_tail...Value=%d (1=OK)\n", i);
    i = list_is_tail(list_head(&list));
    fprintf(stdout, "Testing list_is_tail...Value=%d (0=OK)\n", i);


    /***********************************************/
    print_log_header("EXAMPLE #9");
    /***********************************************/

    fprintf(stdout, "Destroying the list\n");
    list_destroy(&list);

    return 0;
}



/* ------------------------------- list_init ----------------------------- */
void list_init(List *list, void (*destroy)(void *data)) {

    /* Initialize the list */
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

}

/* ----------------------------- list_destroy ---------------------------- */
void list_destroy(List *list) {

    void               *data;

    /* Remove each element */
    while (list_size(list) > 0) {

       if (list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy !=
	  NULL) {

	  /* Call a user-defined function to free dynamically allocated data */
	  list->destroy(data);

       }

    }

    /* No operations are allowed now, but clear the structure as a precaution */
    memset(list, 0, sizeof(List));

}

/* ----------------------------- list_ins_next --------------------------- */

// SOURCE IN: list_ins_next.c

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


