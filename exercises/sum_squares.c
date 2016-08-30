#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sum_squares(int, int);

//****************************************************************************
/*
int sum_squares(int m, int n)
{
    (to compute the sum of the squares in the range m:n, where m<=n)

    if (there is more than one number in the range m:n) {
        (the solution is gotten by adding the square of n to)
        (the sum of the squares in the range m:n-1)
    } else {
        (there is only one number in the range m:n, so m == n, and)
        (the solution is therefore just the square of n)
    }

}
*/

//****************************************************************************

/* assume m <= n */
int sum_squares(int m, int n){
    //(to compute the sum of the squares in the range m:n, where m<=n)
    int middle; 

    //if (there is more than one number in the range m:n) {
    if (m == n){   // the base case
        //(the solution is gotten by adding the square of n to)
        //(the sum of the squares in the range m:n-1)
        return m*m;
    } else {
        //(there is only one number in the range m:n, so m == n, and)
        //(the solution is therefore just the square of n)
        middle = (m+n)/2;
        return sum_squares(m, middle) + sum_squares(middle + 1, n);
    }
}

//****************************************************************************
int main() {
    int x;
    x = sum_squares(2, 4);
    printf("%i", x);
    return 0;
}
