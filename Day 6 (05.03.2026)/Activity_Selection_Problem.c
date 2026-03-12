#include <stdio.h>

int main() {

    int n = 7;

    int start[]  = {1,3,0,5,8,5,6};
    int finish[] = {2,4,6,7,9,9,10};

    int i, j;

    printf("Selected Activities:\n");

    printf("A1 ");

    i = 0;

    for(j = 1; j < n; j++) {

        if(start[j] >= finish[i]) {

            printf("A%d ", j+1);

            i = j;
        }
    }

    return 0;
}

/*
OUTPUT:

Selected Activities:
A1 A2 A4 A5 
*/