#include <stdio.h>     //FINDING THE FIRST OCCURENCE OF A NUMBER IN A SORTED ARRAY
#include <stdlib.h>

int findFirstOccurence(int arr[],int n,int target){
	int low = 0,high = n-1 ;
	int result = -1 ;
	while(low<=high){
		int mid = low+(high-low)/2 ;
		if(arr[mid] == target){
			result = mid ;
			high = mid - 1 ;
		}
		else if(arr[mid] < target){
			low = mid+1 ;
		}
		else{
			high = mid-1 ;
		}
	}
	return result ;
}

int main(){
	int n,target ;
	printf("Enter size of array: ");
	scanf("%d",&n);
	
	int *arr = (int*)malloc(n * sizeof(int));
    // check for memory allocation failing 
    if(arr == NULL){
        printf("Memory allocation failed\n");
        return -1;
    }
    
	printf("Enter %d elements in sorted order:\n",n);
	for(int i=0;i<n;i++){
		scanf("%d",(arr + i));
	}
	
	printf("Enter target element: ");
	scanf("%d",&target);
	
	int index = findFirstOccurence(arr,n,target) ;
	
	if (index != -1){
		printf("First Occurence of %d is at index %d\n",target,index) ;
	}
	else{
		printf("Element %d not found in the array\n",target) ;
	}
	return 0 ;
}