// PROBLEM: Reverse the order of items in a linked-list
// p. 77,78

// L = (SAN, ORD, BRU, DUS)
// Head(L) = (SAN)
// Tail(L) = (ORD, BRU, DUS)

// ITERATIVE SOLUTION

// Program 3.15 
void list_reverse(NodeType **L)    // to reverse a list L
{
    NodeType *R, *N, *L1;
    L1 = *L;                 // L1 points to the first node of the list to reverse
    R = NULL;                // initialize R, the reversed list, to the empty list
    while(L1 != NULL) {
        N = L1;              // let N point to L1's first node
        L1 = L1->Link;       // now, let L1 point to the remainder of L1
        N->Link = R;         // link N to the rest of R
        R = N;               // and make R point to its new first node
    }
    *L = R;                  // finally, replace L by a pointer to the reversed list R
}

// RECURSIVE SOLUTION

// Take a look at our example L
// write out both L and its reversed
// L                = (SAN, ORD, BRU, DUS)
// Reverse(L)       = (DUS, BRU, ORD, SAN)
// Tail(L)          = (ORD, BRU, DUS)
// Reverse(Tail(L)) = (DUS, BRU, ORD)
// Head(L)          = (SAN)
// Reverse(Head(L)) = (SAN)


// A possible solution could result if we could concatenate (i.e. join together) the 2
// lists: list_reverse(Tail(L)) and Head(L)

// We need to solve 3 problems:
// (1). deciding how to reverse the empty list
// (2). finding out how to partition a non-empty list into its Head and its Tail
// (3). writing a function to concatenate (or join together) 2 lists into a single list

// it seems reasonable that the reverse of an empty list is an empty list
// so let list_reverse(NULL) == NULL

// NOTE:
// the function Partition(L, &Head, &Tail) is not defined if L is the empty list

// The next problem is to partition L into a Head and a Tail.
// The solution to this is shown in Program Strategy 3.18

/*
//Program Strategy 3.17
NodeType *list_reverse(NodeType *L)
{
    // to reverse a list L
    if (L is the empty list) {
        // the result is the reverse of the empty list      // base case
    } else {
        // in the case L is non-empty
        // partition the list L into the Head and Tail
        // then, concatenate the Reverse of the Tail of L   // recursion step
        // with the Head of L
    }
}
*/




// Program Strategy 3.18
void Partition(NodeType *L, NodeType **Head, NodeType **Tail)
{
    // to divide list L into its Head & Tail
    if(L != NULL) {
        *Tail = L->Link;            // Tail contains all nodes of L after the first
        *Head = L;                  // Head contains just the first node of L
        (*Head)->Link = NULL;       // mark the end of the Head node
    }
}

NodeType *Concat(NodeType *L1, NodeType *L2)
{
    NodeType *N;

    if(L1 == NULL) {
        return L2;
    } else {
        N = L1;                             // let N point to the first node of L1 
        while(N->Link != NULL)N = N->Link;  // find the last node of L1
        N->Link = L2;                       // set the link of the last node of L1 to L2
        return L1;                          // return the pointer to the concatenated lists
    }
}

// Program 3.19 - refinement for reverse(L)
NodeType list_reverse2(NodeType *L)
{
    NodeType *Head, *Tail;
  
    if(L == NULL) {
        return NULL;                        // base case
    } else {
        Partition(L, &Head, &Tail);         // divide L into Head and Tail
        return Concat(Reverse(Tail), Head); // recursion step
    }

}
