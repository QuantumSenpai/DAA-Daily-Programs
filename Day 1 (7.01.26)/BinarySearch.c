#include <stdio.h>

int main() {
    int a[] = {5, 9, 17, 21, 25};
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
//OUTPUT OF THE ABOUVE CODE:
/*
Step 1: low=0 high=4 mid=2 checking 17
Step 2: low=0 high=1 mid=0 checking 5
Step 3: low=1 high=1 mid=1 checking 9
Element found at position 2
*/

