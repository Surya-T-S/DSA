#include <stdio.h>
#include <stdlib.h>

// bin search function
int binary_search(int arr[],int key, int low, int high){

	if(low>high){
		return -1;
	}

	int mid = (low+high)/2;
	if(arr[mid] == key){
		return mid;
	}
	else if(arr[mid]>key){
		return binary_search(arr,key,low,mid-1);
	}
	else{
		return binary_search(arr,key,mid+1,high);
	}
}

int main(){
	int n,key;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);

    // dynamic memory allocation
	int *arr = (int*)malloc(n * sizeof(int));
    // check for memory allocation failing 
    if(arr == NULL){
        printf("Memory allocation failed\n");
        return -1;
    }
	
	printf("Enter the elements of the array:\n");
	for(int i=0; i<n; i++){
		printf("Enter the %d element: ",i);
		scanf("%d",(arr + i));     // arr + i or &arr[i]
	}
	printf("Enter the key to be searched: ");
	scanf("%d",&key);


	int index = binary_search(arr, key, 0, n - 1);
    if (index == -1) {
    	printf("Element not found!\n");
    }
	else {
    	printf("Element found at the index %d\n", index);
  	}
    free(arr);
	return 0;
}