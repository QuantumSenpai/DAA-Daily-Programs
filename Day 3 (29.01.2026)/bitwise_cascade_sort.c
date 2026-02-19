#include <stdio.h>

void swap(int *a, int *b, int index1, int index2) {
    printf("Swapping arr[%d]=%d and arr[%d]=%d\n", 
           index1, *a, index2, *b);

    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Bitwise Cascade Sort
void bitwiseCascadeSort(int arr[], int start, int end, int bit, int n) {
    if (start >= end || bit < 0)
        return;

    int left = start;
    int right = end;

    printf("\nPartitioning on bit position %d\n", bit);

    while (left <= right) {
        if (((arr[left] >> bit) & 1) == 0) {
            left++;
        } else {
            swap(&arr[left], &arr[right], left, right);
            right--;
        }
    }

    printf("Array after partition on bit %d: ", bit);
    printArray(arr, n);

    bitwiseCascadeSort(arr, start, right, bit - 1, n);
    bitwiseCascadeSort(arr, right + 1, end, bit - 1, n);
}

int main() {
    int arr[] = {7, 3, 1, 9, 8, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    // Max element < 16 → 4 bits → start from bit index 3
    bitwiseCascadeSort(arr, 0, n - 1, 3, n);

    printf("\nFinal Sorted Array: ");
    printArray(arr, n);

    return 0;
}

/*
------------------------ OUTPUT ------------------------

Original Array: 7 3 1 9 8 2 6 4

Partitioning on bit position 3
Swapping arr[0]=7 and arr[7]=4
Swapping arr[1]=3 and arr[6]=6
Swapping arr[2]=1 and arr[5]=2
Swapping arr[3]=9 and arr[4]=8
Array after partition on bit 3: 4 6 2 8 9 1 3 7

Partitioning on bit position 2
Swapping arr[0]=4 and arr[2]=2
Array after partition on bit 2: 2 6 4 8 9 1 3 7
...

Final Sorted Array: 1 2 3 4 6 7 8 9

---------------------------------------------------------
*/
