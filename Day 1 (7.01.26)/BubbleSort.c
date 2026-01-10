#include <stdio.h>

int main() {
    int a[] = {41, 34, 1, 22};
    int n = 4;
    int i, j, t;

    for(i = 0; i < n - 1; i++) {
        printf("\nPass %d\n", i + 1);

        for(j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }

        for(int k = 0; k < n; k++)
            printf("%d ", a[k]);
        printf("\n");
    }

    return 0;
}
