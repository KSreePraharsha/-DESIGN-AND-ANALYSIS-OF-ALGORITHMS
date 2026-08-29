#include <stdio.h>
#define SIZE 10
int hash[SIZE];
int main(){
    int x, key, index;
    int i;
    for (x = 0; x < SIZE; x++){
        hash[x] = -1;
    }
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (x = 0; x < n; x++){
        printf("Enter the elements:\n");
        scanf("%d", &key);
        index = key % SIZE;
        i = 1;

        while (hash[index] != -1){
            index = (index + (i * i)) % SIZE;
            i++;
        }
        hash[index] = key;
    }
    printf("The elements in the hash table:\n");
    for (x = 0; x < SIZE; x++){
        printf("%d\n", hash[x]);
    }
    return 0;
}
