/*
Question 1:
Write a C program whose time complexity is exactly
T(n) = 3n^2 + 2n + 4 using step count.

Exact Time Complexity:
T(n) = 3n^2 + 2n + 4

Asymptotic Complexity:
O(n^2)
*/

#include <stdio.h>

int main() {
    int n = 5, i, j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) ;
        for(j = 0; j < n; j++) ;
        for(j = 0; j < n; j++) ;
    }

    for(i = 0; i < n; i++) ;
    for(i = 0; i < n; i++) ;

    ;
    ;
    ;
    ;

    return 0;
}

/*
Output:
No visible output (program used for step count analysis)
*/
