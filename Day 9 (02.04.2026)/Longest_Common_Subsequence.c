/*
Question:
Find the length and string of LCS using Tabulation Method.

S1 = BCDAACD
S2 = ACDBAC

Also print the DP table.
*/

#include <stdio.h>
#include <string.h>

int max(int a,int b){ return a>b?a:b; }

int main(){

    char X[]="BCDAACD";
    char Y[]="ACDBAC";

    int m=strlen(X), n=strlen(Y);
    int L[20][20];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0) L[i][j]=0;
            else if(X[i-1]==Y[j-1])
                L[i][j]=L[i-1][j-1]+1;
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
    }

    // Print Table
    printf("DP Table:\n");
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            printf("%d ",L[i][j]);
        }
        printf("\n");
    }

    printf("\nLength = %d\n",L[m][n]);

    // Build LCS
    char lcs[20];
    int i=m,j=n,index=L[m][n];
    lcs[index]='\0';

    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            lcs[index-1]=X[i-1];
            i--; j--; index--;
        }
        else if(L[i-1][j]>L[i][j-1]) i--;
        else j--;
    }

    printf("LCS = %s",lcs);
}

/*
Output:
DP Table:
0 0 0 0 0 0 0
0 0 0 0 1 1 1
0 1 1 1 1 1 2
0 1 2 2 2 2 2
1 1 2 2 3 3 3
1 1 2 2 3 3 3
1 2 2 2 3 4 4
1 2 3 3 3 4 4

Length = 4
LCS = ACAC
*/