#include <stdio.h>       // BINARY SEARCH IN ROTATED SORTED ARRAY
#include <stdlib.h>

int searchinRotatedArray(int arr[],int n,int target){
	int low = 0 , high = n-1 ;
	while(low <= high){
		int mid = low + (high-low)/2 ; 
		
		if (arr[mid] == target)
			return mid ;
		
		if (arr[low] <= arr[mid]){
			if(arr[low] <= target && target < arr[mid]){
				high = mid-1 ;
			}
			else{
				low = mid + 1 ;
			}
		}
		else{
			if(arr[mid] < target && target <= arr[high])
				low = mid + 1 ;
			else
				high = mid - 1 ;
		}
	}
	return -1 ;
}

int main(){
	int n,target ;
	printf("Enter size of array: ");
	scanf("%d",&n);
	
	// dynamic memory allocation
    int *arr = (int*)malloc(n * sizeof(int));
    // check for memory allocation failing 
    if(arr == NULL){
        printf("Memory allocation failed\n");
        return -1;
    }
	
	printf("Enter %d elements of rotated sorted array:\n",n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	printf("Enter target element: ");
	scanf("%d",&target);
	
	int index = searchinRotatedArray(arr,n,target) ; 
	
	if(index != -1){
		printf("Element %d found at index %d \n",target,index);
	}	
	else{
		printf("Element %d not found in the array\n",target);
	}
	return 0;
}