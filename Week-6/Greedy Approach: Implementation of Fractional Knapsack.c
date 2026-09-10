#include <stdio.h>
void knapsack(int n, int weight[], int profit[], int capacity){
    int i, j, temp;
    float ratio[10], total = 0, amount;
    for (i = 0; i < n; i++)
        ratio[i] = (float)profit[i] / weight[i];
    for (i = 0; i < n - 1; i++){
        for (j = i + 1; j < n; j++){
            if (ratio[i] < ratio[j]){
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++){
        if (capacity >= weight[i]){
            capacity = capacity - weight[i];
            total = total + profit[i];
        }
        else{
            amount = (float)capacity / weight[i];
            total = total + profit[i] * amount;
            break;
        }
    }
    printf("Maximum profit = %.2f\n", total);
}
int main(){    
    int n, i, capacity;
    int weight[10], profit[10];
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    printf("Enter profits:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &profit[i]);
    printf("Enter capacity: ");
    scanf("%d", &capacity);
    knapsack(n, weight, profit, capacity);
    return 0;
}
