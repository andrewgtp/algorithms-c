#include <stdlib.h>
#include <stdio.h>
#include "headers.h"


int list_ins_next(List *list, ListElmt *element, const void *data) {

    // HINT:
    // List == chain
    // ListElemt == link (node) in chain

    // Create a new node called: new_element 

    // CODE:
    ListElmt *new_element;

    // Allocate memory for new_element
    // HINT: wrap in a conditional and return -1 if unable to allocate
    if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
        return -1;

    // Assign data into new element 
    // TODO: why do we need (void *) in front? Why do we need to cast to void here

    //CODE
    new_element->data = (void *)data;


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
        if (element->next == NULL)
            list->tail = new_element;

	// Assign new_element node's next ptr to element node's next ptr
	new_element->next = element->next;

	// Assign element node's next ptr to new_element
	element->next = new_element;
    }
    if ((element == NULL) && (list->head == list->tail)) {
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("[A]. in an empty list\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    }
    if ((element == NULL) && (list->head != list->tail)) {
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("[B]. in front of HEAD\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    }
    if ((element != NULL) && (element->next == NULL)) {
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("[C]. after TAIL\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    }
    if ((element != NULL) && (element->next != NULL)) {
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("[D]. somewhere between HEAD & TAIL\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    }

    // **************************************************************************

    /*
    // We have a new element not linked to anything (and whos next pointer points to NULL)
    // Here is out list where we want to insert a new element
    // We could insert it in one of 3 ways:

    // [A]. in an empty list 
    // [B]. in front of HEAD 
    // [C]. after TAIL 
    // [D]. somewhere between HEAD & TAIL 

    // =============================================== 
    // SCENARIO A: in an empty list 
    // =============================================== 

		   new_element
		+---------+---+--+ 
    list:       |         | NULL |
		+---------+---+--+
     
                 ^^^^^ HEAD ^^^^^      
                 ^^^^^ TAIL ^^^^^ 


    // =============================================== 
    // SCENARIO B: in front of HEAD 
    // =============================================== 

		   new_element
		+---------+---+--+     +---------+---+--+     +---------+------+
    list:       |         | NULL |     |         |   *  +----->         | NULL |
		+---------+---+--+     +---------+------+     +---------+------+
     
					^^^^^ HEAD ^^^^^      ^^^^^ TAIL ^^^^^ 



    // =============================================== 
    // SCENARIO C: after TAIL
    // =============================================== 

											new_element
				       +---------+---+--+     +---------+------+     +---------+------+
    list:                              |         |   *  +----->         | NULL |     |         | NULL |
				       +---------+------+     +---------+------+     +---------+------+
     
					^^^^^ HEAD ^^^^^      ^^^^^ TAIL ^^^^^ 


    // =============================================== 
    // SCENARIO D: somewhere between HEAD & TAIL 
    // =============================================== 

								 new_element
							      +---------+------+
    new:                                             +-------->         |   *  +-----------+
						     |        +---------+------+           |
						     |                                     |
						     |                                     |
						     |                                     |
				       +---------+---+--+                            +-----v---+------+
    list:                              |         |   *  +---------------------------->         | NULL |
				       +---------+------+                            +---------+------+
     
					^^^^^ HEAD ^^^^^                              ^^^^^ TAIL ^^^^^ 
    */


    // Adjust the size of the list to account for the inserted element.
    list->size++;    
    return 0;
}

// ===============================
// TEMPLATE
// ===============================

/*
                                                          +---------+------+
new:                                             +-------->         |   *  +-----------+
                                                 |        +---------+------+           |
                                                 |          new_element next           |
                                                 |                                     |
                                                 |                                     |
            +---------+---+--+     +---------+---+--+                            +-----v---+------+
list:       |         |   *  +----->         |   *  +---------------------------->         |   *  |
            +---------+---+--+     +---------+------+                            +---------+------+
                                     element   next
 
             ^^^^^ HEAD ^^^^^       ^^^^^ HEAD ^^^^^                              ^^^^^ TAIL ^^^^^ 
*/
