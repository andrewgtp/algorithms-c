/*
void list_rem_last(&L)  // &L gives the address of the variable L
{
    // Let PreviousNode and CurrentNode contain pointers to list nodes
    
    if (L is not the empty-list) {
	if (L has exactly one node) {

            // free the node's storage, replace L with the empty list
            // and return from the procedure

        } else {          // otherwise, L must have 2 or more nodes
            // initialize a pair of pointers, (PreviousNode, CurrentNode))
            // to point to the first and second nodes
  
            // Advance the pointer pair along L until CurrentNode
            // points to the last node
   
            while (CurrentNode does not point to the last node) {
                // advance the pair of pointers to the next pair of nodes
            }
   
            // Now PreviousNode points to the next-to-last node on the list
            // and CurrentNode points to the last node on the list

            // Finally, change the next-to-last node into the new last node
            // and free the space for the discarded last node
	} 
    }
}
*/


void list_rem_last(NodeType **L)  // &L gives the address of the variable L
                                  // Note: **L is the address of the varialbe L,
                                  //       whose value points to the 1st node of list L
{
    // Let PreviousNode and CurrentNode contain pointers to list nodes
    NodeType *PreviousNode, *CurrentNode;
    
    // if (L is not the empty-list) {
    if (*L != NULL) {                     // do nothing if *L was the empty list

	//if (L has exactly one node) {
	if ((*L)->Link == NULL) {         // if *L has exactly one node, then....

            free(*L);                     // free the node's storage, 

            // replace L with the empty list
            *L = NULL;                    // set L to be empty list, and terminate
            // and return from the procedure

        } else {          // otherwise, L must have 2 or more nodes
            // initialize a pair of pointers, (PreviousNode, CurrentNode))
            // to point to the first and second nodes
            PreviousNode = *L;
            CurrentNode = (*L)->Link;
  
            // Advance the pointer pair along L until CurrentNode
            // points to the last node
   
            //while (CurrentNode does not point to the last node) {
            while (CurrentNode->link != NULL) {
                // advance the pair of pointers to the next pair of nodes
                PreviousNode = CurrentNode;
                CurrentNode = CurrentNode->Link;
            }
   
            // Now PreviousNode points to the next-to-last node on the list
            // and CurrentNode points to the last node on the list
            // Finally, change the next-to-last node into the new last node
            // and free the space for the discarded last node
            PreviousNode->Link = NULL;      // last node gts NULL link
            free(CurrentNode);              // recycle storage for discarded node

	} 
    }
}
