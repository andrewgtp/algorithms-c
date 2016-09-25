#include <stdlib.h>
#include "headers.h"


int list_ins_next(List *list, ListElmt *element, const void *data) {

    // here's your new element!
    ListElmt *new_element;

    // alloc mem for new_element

    // Insert data into new element 

/*       
                                           +---------+------+
      new_element:                         | *data   | NULL |
                                           +---------+------+
                                                       next
*/

    // Handle insertion somewhere at the head

    // Handle insertion somewhere other than at the head


/*               +---------+------+
       element:  |         | NULL |
                 +---------+------+
                             next
*/  

    // set tail = new_element
/*                                                                    +---------+------+
                                                                      |         | NULL |
                                                                      +---------+------+
                                                                       new_element next
    
                 +---------+------+                                   +---------+------+
       list:     |         |   *  |----------------------------------->         |   *  |
                 +---------+------+                                   +---------+------+
                                                                                  
*/

    // assign new_element next ptr to element next ptr

/*
                                           +---------+------+
 element:                                  |         |   *  +---------------+
                                           +---------+------+               |
                                            new_element next                |
                                                                            |
                                                                            |
                 +---------+---+--+                                   +-----v---+------+
 list:           |         |   *  |----------------------------------->         |   *  |
                 +---------+------+                                   +---------+------+
                   element   next
*/

    // assign element next ptr to new_element

/*
                                           +---------+------+
 element:                      +----------->         |   *  +---------------+
                               |           +---------+------+               |
                               |            new_element next                |
                               |                                            |
                               |                                            |
                 +---------+---+--+                                   +-----v---+------+
 list:           |         |   *  |                                   |         |   *  |
                 +---------+------+                                   +---------+------+
                   element   next
*/

    }

    /* Adjust the size of the list to account for the inserted element */
    return 0;
}

