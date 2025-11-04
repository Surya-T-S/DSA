
// Sorts an array using the insertion sort algorithm.
#include <stdio.h>    // INSERTION SORT
#include <stdlib.h>

void insertionSort(int *arr,int n){
	for(int i=1 ; i<n ; i++){
		int key = arr[i] ;
		int j = i-1 ;
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j] ;
			j-- ;
		}
		arr[j+1] = key ;
	}
}

int main(){
	int n ;
	printf("Enter the number of elements: ") ;
	scanf("%d",&n) ;
	
	int *arr = (int*)malloc(n * sizeof(int));
    // check for memory allocation failing 
    if(arr == NULL){
        printf("Memory allocation failed\n");
        return -1;
    }
    
	printf("Enter %d elements:\n",n) ;
	for(int i=0 ; i<n ; i++){
		scanf("%d",&arr[i]) ;
	}
	
	insertionSort(arr,n) ;
	
	printf("Sorted Array using Insertion Sort:\n") ;
	for(int i=0 ; i<n ; i++){
		printf("%d ",arr[i]) ;
	}
	printf("\n") ;
	
	return 0 ;
}