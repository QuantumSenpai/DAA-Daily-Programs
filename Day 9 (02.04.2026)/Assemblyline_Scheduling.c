/*
Question:
Solve Assembly Line Scheduling using Dynamic Programming.

Company 1 (a1): 3 10 12 6 7 11
Company 2 (a2): 5 11 8 9 7 8

Transfer times:
t1: 2 3 1 3 4
t2: 2 1 2 2 1

Entry times:
e1 = 3, e2 = 5

Exit times:
x1 = 2, x2 = 1

Find:
1. Minimum Cost
2. Print Cost Table (f1, f2)
*/

#include <stdio.h>

int min(int a,int b){ return a<b?a:b; }

int main(){

    int a1[] = {3,10,12,6,7,11};
    int a2[] = {5,11,8,9,7,8};

    int t1[] = {2,3,1,3,4};
    int t2[] = {2,1,2,2,1};

    int e1 = 3, e2 = 5;
    int x1 = 2, x2 = 1;

    int n = 6;

    int f1[10], f2[10];

    f1[0] = e1 + a1[0];
    f2[0] = e2 + a2[0];

    printf("Cost Table:\n");
    printf("Station\tf1\tf2\n");
    printf("1\t%d\t%d\n", f1[0], f2[0]);

    for(int i=1;i<n;i++){

        f1[i] = min(
            f1[i-1] + a1[i],
            f2[i-1] + a1[i] + t2[i-1]
        );

        f2[i] = min(
            f2[i-1] + a2[i],
            f1[i-1] + a2[i] + t1[i-1]
        );

        printf("%d\t%d\t%d\n", i+1, f1[i], f2[i]);
    }

    int final1 = f1[n-1] + x1;
    int final2 = f2[n-1] + x2;

    int ans = min(final1, final2);

    printf("\nMinimum Cost = %d\n", ans);

    return 0;
}

/*
Output:

Cost Table:
Station f1 f2
1       6  10
2       16 21
3       28 27
4       34 36
5       41 43
6       52 51

Minimum Cost = 47
*/