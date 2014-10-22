// A basic example of binary search.

// In binary search we keep a max, mid and min. If the target falls to the left of min and mid we reset max,
// if target falls to the right we reset min. Continue until we narrow down / find the target.
//
// Note: requires a sorted array by ascending / descending order.

#include <stdlib.h>
#include <stdio.h>

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

int main() {

    int arrSize = 50;
    int array[arrSize];

    for (int i = 0; i <= arrSize - 1; i++) {
        array[i] = 2 * i;
    }

    printf("Binary search %d return: %s\n", 5, binarySearch(array, 5, arrSize) > 1 ? "true" : "false");
    printf("Binary search %d return: %s\n", 6, binarySearch(array, 6, arrSize) > 1 ? "true" : "false");
    printf("Binary search %d return: %s\n", 98, binarySearch(array, 98, arrSize) > 1 ? "true" : "false");
    printf("Binary search %d return: %s\n", 54, binarySearch(array, 54, arrSize) > 1 ? "true" : "false");
    printf("Binary search %d return: %s\n", 53, binarySearch(array, 53, arrSize) > 1 ? "true" : "false");

};
