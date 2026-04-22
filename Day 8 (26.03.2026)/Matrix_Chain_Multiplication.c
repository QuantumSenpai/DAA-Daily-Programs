/*
Question:
Solve Matrix Chain Multiplication using Dynamic Programming (Tabulation Method)

Given matrices:
A1: 5x4
A2: 4x6
A3: 6x2
A4: 2x7

Find:
1. Minimum number of multiplications
2. Show DP table
*/

#include <stdio.h>

int min(int a, int b){
    return (a < b) ? a : b;
}

int main(){

    int p[] = {5,4,6,2,7};  
    int n = 4; 

    int m[10][10];

    for(int i=1;i<=n;i++)
        m[i][i] = 0;

    for(int L=2; L<=n; L++){

        for(int i=1; i<=n-L+1; i++){

            int j = i + L - 1;
            m[i][j] = 99999;

            for(int k=i; k<j; k++){

                int cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if(cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    printf("DP Table:\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>j)
                printf("0 ");
            else
                printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("\nMinimum Multiplication Cost = %d\n", m[1][n]);

    return 0;
}

/*
Output:

DP Table:
0 120 88 158
0 0 48 104
0 0 0 84
0 0 0 0

Minimum Multiplication Cost = 158
*/