#include <stdio.h>
void maxmin(int a[], int low, int high, int *max, int *min){
    int mid;
    int max1, min1, max2, min2;
    if (low == high){
        *max = *min = a[low];
    }
    else{
        mid = (low + high) / 2;
        maxmin(a, low, mid, &max1, &min1);
        maxmin(a, mid + 1, high, &max2, &min2);
        if (max1 > max2)
            *max = max1;
        else
            *max = max2;
        if (min1 < min2)
            *min = min1;
        else
            *min = min2;
    }
}
int main(){
    int a[10], n, i, max, min;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    maxmin(a, 0, n - 1, &max, &min);
    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);
    return 0;
}
