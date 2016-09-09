//int list_ins_next(List *list, ListElmt *element, const void *data) {

ListElmt *new_element;
new_element = (ListElmt *)malloc(sizeof(ListElmt))
// Insert the element into the list
new_element->data = (void *)data;

/*       
                                           +---------+------+
      new_element:                         | *data   | NULL |
                                           +---------+------+
                                                       next
*/

// Handle insertion somewhere other than at the head
if (element->next == NULL) {
    /*           +---------+------+
       element:  |         | NULL |
                 +---------+------+
                             next
    */  
    list->tail = new_element;
    /*                                                                +---------+------+
                                                                      |         | NULL |
                                                                      +---------+------+
                                                                       new_element next
    
                 +---------+------+                                   +---------+------+
       list:     |         |   *  |----------------------------------->  TAIL   |   *  |
                 +---------+------+                                   +---------+------+
                                                                                  
    */
}


new_element->next = element->next;
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
element->next = new_element;
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

    /* Adjust the size of the list to account for the inserted element */
    list->size++;
}

