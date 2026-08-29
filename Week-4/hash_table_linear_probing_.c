#include <stdio.h>
#define SIZE 10
int hash[SIZE];
int main(){
    int x, key, index;
    for (x = 0; x < SIZE; x++){
        hash[x] = -1;
    }
    int n;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    for (x = 0; x < n; x++){
        printf("Enter the elements:\n");
        scanf("%d", &key);
        index = key % SIZE;
        
        while (hash[index] != -1){
            index = (index + 1) % SIZE;
        }
        hash[index] = key;
    }
    printf("The elements in the hash table:\n");
    for (x = 0; x < SIZE; x++){
        printf("%d\n", hash[x]);
    }
    return 0;
}
