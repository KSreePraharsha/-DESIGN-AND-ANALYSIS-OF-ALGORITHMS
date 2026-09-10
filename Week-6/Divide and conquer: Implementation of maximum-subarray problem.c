#include <stdio.h>
int max(int a, int b){
    return (a > b) ? a : b;
}
int maxcrossingsum(int a[], int low, int mid, int high){
    int leftsum = -9999;
    int rightsum = -9999;
    int sum = 0;
    int i;
    for (i = mid; i >= low; i--){
        sum = sum + a[i];

        if (sum > leftsum)
            leftsum = sum;
    }
    sum = 0;
    for (i = mid + 1; i <= high; i++){
        sum = sum + a[i];

        if (sum > rightsum)
            rightsum = sum;
    }
    return leftsum + rightsum;
}
int maxsubarray(int a[], int low, int high){
    int mid;
    int left, right, cross;
    if (low == high)
        return a[low];
    mid = (low + high) / 2;
    left = maxsubarray(a, low, mid);
    right = maxsubarray(a, mid + 1, high);
    cross = maxcrossingsum(a, low, mid, high);
    return max(max(left, right), cross);
}
int main(){
    int a[10], n, i, result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    result = maxsubarray(a, 0, n - 1);
    printf("Maximum subarray sum = %d\n", result);
    return 0;
}
