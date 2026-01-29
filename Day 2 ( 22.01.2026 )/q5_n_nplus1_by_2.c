/*
Question 5:
Write a C program using nested loops whose exact time
complexity is T(n) = n(n+1)/2.

Exact Time Complexity:
T(n) = n(n + 1) / 2

Asymptotic (Big-O) Complexity:
O(n^2)
*/

#include <stdio.h>

int main() {
    int n = 5, i, j;

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) ;
    }

    return 0;
}

/*
Output:
No visible output
*/
