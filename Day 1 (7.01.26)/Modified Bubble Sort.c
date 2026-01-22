#include <stdio.h>

int main() {
    int a[] = {1, 3, 2, 4};
    int n = 4;
    int i, j, t, flag;

    for(i = 0; i < n - 1; i++) {
        flag = 0;
        printf("\nPass %d\n", i + 1);

        for(j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                flag = 1;
            }
        }

        for(int k = 0; k < n; k++)
            printf("%d ", a[k]);
        printf("\n");

        if(flag == 0)
            break;
    }

    return 0;
}

/*
Output:

Pass 1
1 2 3 4

Pass 2
1 2 3 4
*/
