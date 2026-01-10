#include <stdio.h>

int main() {
    int a[] = {1, 3, 5, 7, 9};
    int n = 5;
    int key = 9; 
    int low = 0, high = n - 1, mid;
    int found = 0, step = 1;

    while(low <= high) {
        mid = (low + high) / 2;

        printf("Step %d: low=%d high=%d mid=%d checking %d\n",
               step, low, high, mid, a[mid]);

        if(a[mid] == key) {
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;

        step++;
    }

    if(found == 0)
        printf("Element not found in the array\n");

    return 0;
}
