/*
Question:
Solve 0/1 Knapsack using Dynamic Programming (Tabulation Method)

Items: A, B, C, D
Profit: 2, 4, 7, 10
Weight: 1, 3, 5, 7
Max Capacity = 8

Also print the DP table.
*/

#include <stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int main(){

    int profit[] = {2,4,7,10};
    int weight[] = {1,3,5,7};

    int n = 4;
    int W = 8;

    int dp[10][10];

    // Build DP Table
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0 || w==0)
                dp[i][w] = 0;
            else if(weight[i-1] <= w)
                dp[i][w] = max(
                    profit[i-1] + dp[i-1][w-weight[i-1]],
                    dp[i-1][w]
                );
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    printf("DP Table:\n");
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            printf("%d ", dp[i][w]);
        }
        printf("\n");
    }

    printf("\nMaximum Profit = %d\n", dp[n][W]);

    int w = W;
    printf("Selected Items: ");
    for(int i=n;i>0;i--){
        if(dp[i][w] != dp[i-1][w]){
            printf("%c ", 'A' + i - 1);
            w -= weight[i-1];
        }
    }

    return 0;
}

/*
Output:

DP Table:
0 0 0 0 0 0 0 0 0
0 2 2 2 2 2 2 2 2
0 2 2 4 6 6 6 6 6
0 2 2 4 6 7 7 9 11
0 2 2 4 6 7 10 10 12

Maximum Profit = 12
Selected Items: D A
*/