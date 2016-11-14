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
    //int *num_ptr = &num;
    int *num_ptr;
    num_ptr = &num;

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


    printf("# Example 1: Increment num value: num++\n");
    num++;
    
    printf("num: %d\n", num);

    printf("# Example 2: Set num to 10: *num_ptr = 10\n");
    *num_ptr = 10; 

    printf("num: %d\n", num);
 
    printf("# Example 3: Assigning pointer to a void then back:\n");
    void* pv = num_ptr;
    num_ptr = (int*) pv;
    printf("Value of num_ptr: %p\n", num_ptr);

    print_log_header("ARRAY INCREMENT"); 
    printf("# Example 4: Pointer to an array:\n");
    printf("Declare array and pointer to array:\n");
    int nums_arr[] = {22,15,7};
    printf("nums_arr[0]: %d\n", nums_arr[0]);
    printf("nums_arr[1]: %d\n", nums_arr[1]);
    printf("nums_arr[2]: %d\n", nums_arr[2]);
    //Note: pointer to array points to first element!
    int *arr_ptr = nums_arr;
    printf("arr_ptr: %p\n", arr_ptr);
    printf("*arr_ptr: %i\n\n", *arr_ptr);
    printf("Increment array pointer which points to next item in array: arr_ptr++\n");
    arr_ptr++; 
    printf("*arr_ptr: %i\n\n", *arr_ptr);
    printf("Increment array pointer which points to next item in array: arr_ptr++\n");
    arr_ptr++; 
    printf("*arr_ptr: %i\n\n", *arr_ptr);

    printf("# Example 5: Using Functions\n"); 
    void (*foo)();

}

int main() {
    print_log_header_dbl("POINTER DEMO"); 
    basic();
    return 0;
}
