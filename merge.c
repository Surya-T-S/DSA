#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int left,int mid,int right){
	int i,j,k ;
	int n1 = mid-left+1 ;   // size of left sub array
	int n2 = right-mid ;    // size of right sub array
	
	int ls[n1],rs[n2] ;     // temp arrays
	
	// COPYING TO TEMP ARRAY LS
	for(i=0 ; i<n1 ; i++){
		ls[i] = arr[left+i] ;
	}
	// COPYING TO TEMP ARRAY RS
	for(j=0 ; j<n2 ; j++){
		rs[j] = arr[mid+1+j] ; 
	}
	
	i=0 ;
	j=0 ;
	k=left ;
	
	// MERGING LS AND RS BACK INTO arr[]
	while(i<n1 && j<n2){
		if(ls[i] < rs[j]){
			arr[k] = ls[i] ;
			i++ ;
		}
		else{
			arr[k] = rs[j] ;
			j++ ;
		}
		k++ ;
	}
	
	// REMAINING ELEMENTS IN LS
	while(i<n1){
		arr[k] = ls[i] ;
		i++ ;
		k++ ;
	}
	// REMAINING ELEMENTS IN RS
	while(j<n2){
		arr[k] = rs[j] ;
		j++ ;
		k++ ;
	}
}

void mergeSort(int *arr,int left,int right){
	if(left < right){
		int mid = left+(right-left)/2 ;
		
		mergeSort(arr,left,mid) ;
		mergeSort(arr,mid+1,right) ;
		
		merge(arr,left,mid,right) ;
	}
}

int main(){
	// # of elements
	int n ;
	printf("Enter the number of elements: ") ;
	scanf("%d",&n) ;
	
	int *arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed\n");
        return -1;
    }

	for(int i=0 ; i<n ; i++){
		printf("Enter the %d element: ",i+1) ;
		scanf("%d",&arr[i]) ;
	}
	
    printf("Original array:\n") ;
    for(int i=0 ; i<n ; i++){
        printf("%d ",arr[i]) ;
    }
	// merge sort function call
	mergeSort(arr,0,n-1) ; 
	
	printf("\n\nSorted Array using Merge Sort:\n") ;
	for(int i=0 ; i<n ; i++){
		printf("%d ",arr[i]) ;
	}
	printf("\n") ;
	free(arr);
	return 0 ;
}