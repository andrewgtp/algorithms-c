
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "utils.h"

/*
 * Description: Illustrates using a linked list (see Chapter 5).
 */

static void print_list(const List *list) {
    ListElmt           *element;
    int                *data, i;

    // Display the linked list.
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
    int                *data, i;

    print_log_header("HELLO BRO");

    list_init(&list, free);

    // Perform example #1 
    print_log_header("EXAMPLE #1");
    element = list_head(&list);

    for (i = 10; i > 0; i--) {

       if ((data = (int *)malloc(sizeof(int))) == NULL)
	  return 1;

       *data = i;

       if (list_ins_next(&list, NULL, data) != 0)
	  return 1;
    }

    print_list(&list);

    // Perform example #2 
    print_log_header("EXAMPLE #2");
    element = list_head(&list);

    for (i = 0; i < 7; i++)
       element = list_next(element);

    data = list_data(element);
    fprintf(stdout, "Removing an element after the one containing %03d\n", *data);

    if (list_rem_next(&list, element, (void **)&data) != 0)
       return 1;

    print_list(&list);

    // Perform example #3
    print_log_header("EXAMPLE #3");

    fprintf(stdout, "Inserting 011 at the tail of the list\n");

    *data = 11;
    if (list_ins_next(&list, list_tail(&list), data) != 0)
       return 1;

    print_list(&list);

    fprintf(stdout, "Removing an element after the first element\n");

    // Perform example #4 
    print_log_header("EXAMPLE #4");
    element = list_head(&list);
    if (list_rem_next(&list, element, (void **)&data) != 0)
       return 1;

    print_list(&list);

    // Perform example #5 
    print_log_header("EXAMPLE #5");
    fprintf(stdout, "Inserting 012 at the head of the list\n");

    *data = 12;
    if (list_ins_next(&list, NULL, data) != 0)
       return 1;

    print_list(&list);

    // Perform example #6 
    print_log_header("EXAMPLE #6");
    fprintf(stdout, "Iterating and removing the fourth element\n");

    element = list_head(&list);
    element = list_next(element);
    element = list_next(element);

    if (list_rem_next(&list, element, (void **)&data) != 0)
       return 1;

    print_list(&list);

    // Perform example #7
    print_log_header("EXAMPLE #7");
    fprintf(stdout, "Inserting 013 after the first element\n");

    *data = 13;
    if (list_ins_next(&list, list_head(&list), data) != 0)
       return 1;

    print_list(&list);

    // Perform example #8 
    print_log_header("EXAMPLE #8");
    i = list_is_head(&list, list_head(&list));
    fprintf(stdout, "Testing list_is_head...Value=%d (1=OK)\n", i);
    i = list_is_head(&list, list_tail(&list));
    fprintf(stdout, "Testing list_is_head...Value=%d (0=OK)\n", i);
    i = list_is_tail(list_tail(&list));
    fprintf(stdout, "Testing list_is_tail...Value=%d (1=OK)\n", i);
    i = list_is_tail(list_head(&list));
    fprintf(stdout, "Testing list_is_tail...Value=%d (0=OK)\n", i);

    // Perform example #9 
    print_log_header("EXAMPLE #9");
    fprintf(stdout, "Destroying the list\n");
    list_destroy(&list);

    return 0;
}
