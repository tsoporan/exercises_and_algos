#include <stdio.h>
#include <stdlib.h>

/*  Implementation of Quicksort
 *
 *  Summary:
 *      Choose a pivot to compare against
 *      Put all numbers less than the pivot in a sub-array to the left (of pivot)
 *      Put all numbers greater than the pivot in a sub-array to the right (of pivot)
 *      Recurisvely run this until we have sorted the array.
 */

void printArray(int* arr, int size);
int partition(int* arr, int a, int b);

int partition(int* arr, int lo, int hi) {

    int pivot = arr[lo]; // Use first element as pivot
    int left = lo+1; // Start is one past the pivot
    int right = hi; 
    int temp;

    while (1) {

        // Continue until the two cursors, left/right meet.
        while (left <= right) {
            if (arr[left] < pivot) {
                left++; // If we are smaller than the pivot, we are already in the correct place
                        // move to next element.
            } else {
                break; // Break to swap.
            }
        }

        while (right > left) {
            if (arr[right] < pivot) { // If we are smaller than the pivot on the right,
                break; // Break to swap
            } else {
                right--;
            }
        }


        if (left >= right) { // If left has run past right, or we are in the same place
                             // we've compared every item to the pivot.
            break;
        }

        // Swap items left and right.
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // Move along.
        left++;
        right--;

    }

    // Move pivot to the correct place, that is to the left of the current "left"
    // this assures the pivot is in the correct sorted position as all numbers less
    // than pivot will be to the left and all numbers greater to the right.
    arr[lo] = arr[left-1];
    arr[left-1] = pivot;

    return left-1; // Return new pivot point.
};

void sort(int* arr, int lo, int hi) {

    if ((hi-lo) <= 0) { // Only sort if we have two or more elements.
        return;
    }

    int partPoint = partition(arr, lo, hi);

    sort(arr, lo, partPoint - 1); // Left sub-array recursion
    sort(arr, partPoint + 1, hi); // Right sub-array recursion

}

void printArray(int *arr, int size) {
    int i = 0;
    for (; i < size; i++) {
        printf("%i, ", arr[i]);
    }
    printf("\n");
};

int main() {

    int arr1[10] = {5, 2, 7, 3, 4, 9, 8, 1, 6, 10};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("Starting array:\n");
    printArray(arr1, size1);
    sort(arr1, 0, size1-1);
    printf("Sorted array:\n");
    printArray(arr1, size1);

    int arr2[5] = {5,4,3,2,1};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("Starting array:\n");
    printArray(arr2, size2);
    sort(arr2, 0, size2-1);
    printf("Sorted array:\n");
    printArray(arr2, size2);

    int arr3[3] = {1,2,3};
    int size3 = sizeof(arr3)/sizeof(arr3[0]);
    printf("Starting array:\n");
    printArray(arr3, size3);
    sort(arr3, 0, size3-1);
    printf("Sorted array:\n");
    printArray(arr3, size3);

    int arr4[8] = {2,8,2,5,4,3,1,4};
    int size4 = sizeof(arr4)/sizeof(arr4[0]);
    printf("Starting array:\n");
    printArray(arr4, size4);
    sort(arr4, 0, size4-1);
    printf("Sorted array:\n");
    printArray(arr4, size4);
}
