// Counts the number of rotations in a circularly sorted array (user input).
#include <stdio.h>   

int countRotations(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    // dynamic memory allocation
    int *arr = (int*)malloc(n * sizeof(int));
    // check for memory allocation failing 
    if(arr == NULL){
        printf("Memory allocation failed\n");
        return -1;
    }

    printf("Enter %d elements (circularly sorted):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int rotations = countRotations(arr, n);

    printf("Rotations is: %d\n", rotations);

    free(arr);
    return 0;
}