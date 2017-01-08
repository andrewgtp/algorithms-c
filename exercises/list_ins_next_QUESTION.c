#include <stdlib.h>
#include <stdio.h>
#include "list.h"


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

    if (element == NULL) {
        if (list->head == NULL) {
	    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	    printf("[A]. insert in an empty list\n");
	    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	    list->tail = new_element;
	} else {
	    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	    printf("[B]. insert in front of HEAD\n");
	    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	}
	new_element->next = list->head;
	list->head = new_element;     
    } else {
	if (element->next == NULL) {
	    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	    printf("[C]. insert after TAIL\n");
	    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            list->tail = new_element;
	} else {
	    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	    printf("[D]. insert somewhere between HEAD & TAIL\n");
	    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	}
	// Assign new_element node's next ptr to element node's next ptr
	new_element->next = element->next;
	// Assign element node's next ptr to new_element
	element->next = new_element;
    }


    // **************************************************************************

    /*
    // We have a new element not linked to anything (and whos next pointer points to NULL)
    // Here is out list where we want to insert a new element
    // We could insert it in one of 3 ways:

<<<<<<< HEAD
    // [A]. insert in front of HEAD 
    // [B]. insert after TAIL 
    // [C]. insert somewhere between HEAD & TAIL 

    // =============================================== 
    // SCENARIO A: insert in front of HEAD 
=======
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
>>>>>>> 53fee28b10a4012630e92c391f28fd9ee7e1d845
    // =============================================== 

		   new_element
		+---------+---+--+     +---------+---+--+     +---------+------+
    list:       |         | NULL |     |         |   *  +----->         | NULL |
		+---------+---+--+     +---------+------+     +---------+------+
     
					^^^^^ HEAD ^^^^^      ^^^^^ TAIL ^^^^^ 



    // =============================================== 
<<<<<<< HEAD
    // SCENARIO B: insert after TAIL
=======
    // SCENARIO C: after TAIL
>>>>>>> 53fee28b10a4012630e92c391f28fd9ee7e1d845
    // =============================================== 

											new_element
				       +---------+---+--+     +---------+------+     +---------+------+
    list:                              |         |   *  +----->         | NULL |     |         | NULL |
				       +---------+------+     +---------+------+     +---------+------+
     
					^^^^^ HEAD ^^^^^      ^^^^^ TAIL ^^^^^ 


    // =============================================== 
<<<<<<< HEAD
    // SCENARIO C: insert somewhere between HEAD & TAIL 
=======
    // SCENARIO D: somewhere between HEAD & TAIL 
>>>>>>> 53fee28b10a4012630e92c391f28fd9ee7e1d845
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
