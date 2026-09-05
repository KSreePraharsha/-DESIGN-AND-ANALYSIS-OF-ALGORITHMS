#include <stdio.h>
void insertionSort(int bucket[], int n){
    int i, j, key;
    for (i = 1; i < n; i++){
        key = bucket[i];
        j = i - 1;
        while (j >= 0 && bucket[j] > key){
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}
void bucketSort(int arr[], int n){
    int bucket[10][20] = {0};
    int count[10] = {0};
    int i, index, j, k = 0;
    for (i = 0; i < n; i++){
        index = arr[i] / 10;
        bucket[index][count[index]] = arr[i];
        count[index]++;
    }    
    for (i = 0; i < 10; i++){
        insertionSort(bucket[i], count[i]);
    }
    for (i = 0; i < 10; i++){
        for (j = 0; j < count[i]; j++){
            arr[k] = bucket[i][j];
            k++;
        }
    }
}

int main(){
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    bucketSort(arr, n);
    printf("\nSorted array:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
