#include<stdlib.h>
#include<stdio.h>


int product(int, int);

/*
int product(int m, int n) {
    // to compute the product of the integers from m to n
    
    //if (the range m:n has only one integer in it) {
        //return m as the solution, since m == n      // the base case
    //} else {
        //the range m:n must have more than one integer in it, so 
        //compute the midpoint of m:n as the value of the variable middle 
        //and return the product of the integers in the rand m:middle 
        //times the product of the integers in the range middle+1:n 
    //}
    return;
}
*/

int product(int m, int n) {

    int middle;
    // to compute the product of the integers from m to n
    
    //if (the range m:n has only one integer in it) {
    if(m == n){
        //return m as the solution, since m == n      // the base case
        return m;
    } else {
        //the range m:n must have more than one integer in it, so 
        //compute the midpoint of m:n as the value of the variable middle 
        //and return the product of the integers in the rand m:middle 
        //times the product of the integers in the range middle+1:n 
        middle = (m+n)/2;
        return product(m, middle) * product(middle + 1, n);
    }
}

int main() {
    int p = 0;
    printf("hello product!\n");
    p = product(1, 3);
    printf("%i %i %i\n", 1, 3, p); 
    return 0;
}
