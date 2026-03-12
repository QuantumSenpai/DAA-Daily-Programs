#include <stdio.h>

int main() {

    int n = 7;
    float weight[] = {2,5,7,3,1,4,6};
    float profit[] = {10,25,35,15,8,20,30};
    float ratio[7];

    float capacity = 15;
    float totalProfit = 0;

    for(int i=0;i<n;i++) {
        ratio[i] = profit[i] / weight[i];
    }

    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {

            if(ratio[i] < ratio[j]) {

                float temp;

                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }

    for(int i=0;i<n;i++) {

        if(weight[i] <= capacity) {

            capacity -= weight[i];
            totalProfit += profit[i];

        }

        else {

            totalProfit += profit[i] * (capacity / weight[i]);
            break;

        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}

/*
OUTPUT:
Maximum Profit = 78.00
*/