#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *arr,int n){
    for(int i=0; i<n; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}


int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed");
        return -1;
    }

    printf("Enter the elements-->\n");
    for(int i=0; i<n; i++){
        printf("Enter the %d element: ",i+1);scanf("%d",arr + i);
    }
    printf("<-Original Array->\n");
    for(int i=0; i<n; i++){
        printf("%d ",*(arr + i));
    }
    // Function Call for sorting 
    selectionSort(arr,n);

    printf("\n\n<-Sorted Array->\n");
    for(int i=0; i<n; i++){
        printf("%d ",*(arr + i));
    }
    free(arr);
    return -1;
}