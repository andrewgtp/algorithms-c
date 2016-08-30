/*
NodeType *ListSearch(char *A, NodeType *L)
{
    // Declare N to be a variabl that points to nodes
    // Initially, set N to point to the first node of list L
    while (N points to a non-null node on list L {
        if (the Airport code of N's referent equals A) {
            // return the node pointer in N
            } else {
            // advance the pointer N to point to the next node on list L 
        }
    }
    return N's value, NULL, as the result of the list search
}
*/

NodeType *ListSearch(char *A, NodeType *L)
{
    NodeType *N;  /* N points to successive nodes on the list L */
    
    // Initialization
    // Declare N to be a variable that points to nodes
    // Initially, set N to point to the first node of list L
    N = L;        /* let N start by pointing to the first node of the list L */

    // While N points to a non-null node on list L
    // examine the node to which N points
    while (N != NULL) {
        //if (the Airport code of N's referent equals A) {
        if (strcmp(N->Airport, A) == 0) { // if N's Airport == A
            // return the node pointer in N
            return N;
        } else {
            // advance the pointer N to point to the next node on list L 
            N = N->Link  // advance N to the next node on the list
        }
    }
    //return N's value, NULL, as the result of the list search
    return N;            // return NULL if no node's Airport == A
}
