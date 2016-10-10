#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"


// SYNTAX

// equivalent
int* pi;
int * pi;
int *pi;
int*pi;

// read the declaration backwards
const int *pci;
// 1. pci is a variable
// 2. pci is a pointer variable 
// 3. pci is a pointer variable to an integer 
// 4. pci is a pointer variable to a constant integer 

void basic();

void basic() {
    int num = 77;
    int *num_ptr = &num;

    //                          +----------------+
    // num 77    0x7fff59191824 |             77 |
    //                          +----------------+
    // num_ptr   Ox7fff5919182c | 0x7fff59191824 |
    //                          +----------------+
    //           0x7fff59191834 |                |
    //                          +----------------+



    print_log_header("VAR VALUES"); 
    printf("num: %d\n", num);
    printf("num_ptr: %p\n", num_ptr);
    printf("*num_ptr: %i\n\n", *num_ptr);

    print_log_header("VAR ADDRESSES"); 
    printf("&num: %p\n", &num);
    printf("&num_ptr: %p\n\n\n", &num_ptr);
}

int main() {
    print_log_header_dbl("POINTER DEMO"); 
    basic();
    return 0;
}
