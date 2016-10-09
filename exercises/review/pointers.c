#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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

void basic() {
    int num = 77;
    int *num_ptr = &num;

    printf("num: %d\n", num);
    printf("the address of the number....\n");
    printf("&num: %p\n", &num);
    printf("num_ptr: %p\n", num_ptr);
    printf("*num_ptr: %i\n", *num_ptr);
}

int main() {
    basic();
    return 0;
}
