// A basic example of binary search.

// In binary search we keep a max, mid and min. If the target falls to the left of min and mid we reset max,
// if target falls to the right we reset min. Continue until we narrow down / find the target.
//
// Note: requires a sorted array by ascending / descending order.

#include <stdlib.h>
#include <stdio.h>

// Binary search iterative
int binarySearch(int *values, int target, int size) {
    int min = 0;
    int max = size - 1; // length of values - 1

    while (min <= max) {
        int mid = (min + max) / 2;

        if (target < values[mid]) {
            max = mid - 1; // Searching left half
        } else if (target > values[mid]) {
            min = mid + 1; // Searching right half
        } else {
            return mid;
        }
    }

    return -1;

}

// Binary search recursive
int binarySearch1(int target, int first, int last, int *array) {

    // Doesn't exist
    if (first > last) {
        return -1;
    } else {
        int midPoint = (first + last) / 2;
        if (target == array[midPoint]) {
            return midPoint;
        } else {

            if (target < array[midPoint]) {
                return binarySearch1(target, first, midPoint-1, array);
            } else {
                return binarySearch1(target, midPoint+1, last, array);
            }

        }

    }
}

int main() {

    int arrSize = 50;
    int array[arrSize];

    for (int i = 0; i <= arrSize - 1; i++) {
        array[i] = 2 * i;
    }

    int arr[] = {1,2,3,4,5,6,7};
    int arrSize1 = sizeof(arr) / sizeof(int);
    int first = 0;
    int last = arrSize - 1;

    // Recursive
    printf("Return %i\n", binarySearch1(3, first, last, arr));
    printf("Return %i\n", binarySearch1(1, first, last, arr));
    printf("Return %i\n", binarySearch1(9, first, last, arr));
    printf("Return %i\n", binarySearch1(0, first, last, arr));
    printf("Return %i\n", binarySearch1(4, first, last, arr));

    // Iterative
    printf("Binary search %d return: %s\n", 5, binarySearch(array, 5, arrSize) > 1 ? "true" : "false");
    printf("Binary search %d return: %s\n", 6, binarySearch(array, 6, arrSize) > 1 ? "true" : "false");
    printf("Binary search %d return: %s\n", 98, binarySearch(array, 98, arrSize) > 1 ? "true" : "false");
    printf("Binary search %d return: %s\n", 54, binarySearch(array, 54, arrSize) > 1 ? "true" : "false");
    printf("Binary search %d return: %s\n", 53, binarySearch(array, 53, arrSize) > 1 ? "true" : "false");

};
