#include <stdio.h>

void printArray(int arr[], int n) {
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {

    int arr[] = {4,2,2,8,3,3,1};
    int n = 7;

    int max = arr[0];

    for(int i=1;i<n;i++)
        if(arr[i] > max)
            max = arr[i];

    int count[max+1];

    for(int i=0;i<=max;i++)
        count[i] = 0;

    for(int i=0;i<n;i++)
        count[arr[i]]++;

    printf("Pass 1 (Count Array): ");
    for(int i=0;i<=max;i++)
        printf("%d ", count[i]);
    printf("\n");

    for(int i=1;i<=max;i++)
        count[i] += count[i-1];

    printf("Pass 2 (Cumulative Count): ");
    for(int i=0;i<=max;i++)
        printf("%d ", count[i]);
    printf("\n");

    int output[n];

    for(int i=n-1;i>=0;i--) {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    printf("Pass 3 (Sorted Array): ");
    printArray(output,n);

    return 0;
}




/*
OUTPUT:

Pass 1 (Count Array): 0 1 2 2 1 0 0 0 1 
Pass 2 (Cumulative Count): 0 1 3 5 6 6 6 6 7 
Pass 3 (Sorted Array): 1 2 2 3 3 4 8 
*/