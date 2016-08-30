
typedef struct NodeTag{
    AirportCode      Airport;
    struct NodeTag   *LeftLink;
    struct NodeTag   *RightLink;
} NodeType;


int main(void)
{
    NodeType *L;

    // First, construct the list L = (DUS, ORD, SAN) and print it
    // To start things off, let L be the empty list
    L = NULL;

    // Insert a new last node in L with airport code *DUS*
    InsertNewLastNode("DUS", &L);

    // Insert a new last node in L with airport code *ORD*
    InsertNewLastNode("ORD", &L);

    // Insert a new last node in L with airport code *SAN*
    InsertNewLastNode("SAN", &L);

    // Now, print the list, to show what it looks like before changing it
    PrintList(L);

    // Then, insert a new seond node with the airport code "BRU"
    InsertNewSecondNode();

    // Now, print the list, to show what it looks like before changing it
    PrintList(L);

    // Delete the last node of the list 
    DeleteLastNode(&L);

    // Now, print the list, to show what it looks like before changing it
    PrintList(L);






}
