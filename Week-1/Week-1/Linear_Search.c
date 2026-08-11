#include<stdio.h>
int main(){
    int n;
    int count=0;
    int found=0;
       printf("Enter number of elements");
       scanf("%d",&n);
    int arr[n];
    int key;
        printf("Enter the elements");
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
    printf("Enter the Element to search");
    scanf("%d",&key);
    
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            printf("element found at %d",count+1);
            found=1;
            break;
        }else{
              count++;
        }
    }
    if(found==0){
        printf("Element not found");
    }
    return 0;
}
