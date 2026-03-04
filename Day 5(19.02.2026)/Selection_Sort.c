#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    for (int i = 0; i < n - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

        printf("Pass %d: ", i + 1);
        printArray(arr, n);
    }

    return 0;
}




/*OUTPUT:

Original Array:
64 25 12 22 11 
Pass 1: 11 25 12 22 64 
Pass 2: 11 12 25 22 64 
Pass 3: 11 12 22 25 64 
Pass 4: 11 12 22 25 64 
*/