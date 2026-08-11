#include<stdio.h>
int main(){
    int n;
    int count=0;
    int found=0;
    int sorted=0;
      printf("ENter the number of elements");
      scanf("%d",&n);
    int arr[n];
    int key;
      printf("Enter the elements");
       for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
      }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            sorted=1;
            break;
        }
    }
    if(sorted==1){
        printf("Array is not sorted");
        return 0;
    }
    
    printf("Array is sorted\n");
    printf("Enter the element to search");
    scanf("%d",&key);
    
    int low = 0;
    int high=n-1;
    
    while(low<=high){
        int mid=(low+high)/2;
        
        if(arr[mid]==key){
            count=mid;
            printf("Element is found at %d",count+1);
            found =1;
            break;
        }else if(arr[mid]<key){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    if(found==0){
        printf("Element not found");
    }
    return 0;
}
