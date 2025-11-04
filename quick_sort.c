// Sorts an array using the quick sort algorithm.
#include <stdio.h> 
#include <stdlib.h> 

void swap(int *a, int *b);

int partition(int *arr, int low, int high){
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++){
		if (arr[j] < pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	// Move pivot after smaller elements and
	// return its position
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

void quickSort(int *arr, int low, int high){
	if (low < high){
		int pi = partition(arr, low, high);

		// Recursion calls for smaller elements
		// and greater or equals elements
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int main(){	
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	
    int *arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed\n");
        return -1;
    }

	for (int i = 0; i < n; i++){
		printf("Enter the %d element: ", i + 1);
		scanf("%d", &arr[i]);
	}
    printf("Original Array: \n");
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}

	// QUICK SORT FUNCTION CALL
	quickSort(arr, 0, n - 1);

	printf("\n\nSorted Array using Quick sort: \n");
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
    free(arr);
	return 0;
}