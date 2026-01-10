#include <stdio.h>

int main() {
    int a[] = {4, 7, 1, 9, 3};
    int n = 5;
    int key = 9;   
    int i, found = 0;

    for(i = 0; i < n; i++) {
        printf("Checking element %d at position %d\n", a[i], i + 1);

        if(a[i] == key) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Element not found in the array\n");

    return 0;
}
