#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        printf("Pass %d: ", i);
        printArray(arr, n);
    }

    return 0;
}



/*
OUTPUT:

Original Array:
12 11 13 5 6 
Pass 1: 11 12 13 5 6 
Pass 2: 11 12 13 5 6 
Pass 3: 5 11 12 13 6 
Pass 4: 5 6 11 12 13 
*/