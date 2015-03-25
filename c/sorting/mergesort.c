#include <stdio.h>
#include <stdlib.h>

/*  Implementation of Mergesort
 *
 *  Summary:
 *      Recursively break up a list to be sorted in smaller sublists until we are at one item, this is sorted
 *      Work our way up merging the lists until we have reached one list again, this is the sorted list
 */

void printArray(int* arr, int size);
void split(int* A, int* B, int begin, int end);
void merge(int* A, int* B, int begin, int mid, int end);
void copy(int *A, int* B, int being, int end);

void printArray(int *arr, int size) {
    int i = 0;
    for (; i < size; i++) {
        printf("%i, ", arr[i]);
    }
    printf("\n");
};

void split(int* A, int* B, int begin, int end) {

    int mid;

    if ((end - begin) < 2) {
        return;
    }

    mid = (end + begin) / 2;

    split(A, B, begin, mid ); // Split left side

    split(A, B, mid, end); // Split right side

    merge(A, B, begin, mid, end); // Merge the two subarrays

    copy(B, A, begin, end); // Finally copy the elements at the correct location.

};

void merge(int* A, int* B, int begin, int mid, int end) {

    int left = begin;
    int right = mid;

    for (int i = begin; i < end; i++ ) {

        if (left < mid && (right >= end || A[left] <= A[right])) {
            // Left cursor hasn't reached middle
            // Right has finished/fallen off OR
            // First left is smaller or equal to first right

            B[i] = A[left]; // Left side is smaller
            left++;
        } else {
            B[i] = A[right]; // Right side is smaller
            right++;
        }
    }
};

void copy(int* B, int* A, int begin, int end) {
    for (int i = begin; i < end; i++) {
            A[i] = B[i];
    }
}

int main() {

    int A[10] = {5, 3, 8, 9, 6, 1, 2, 0, 7, 4};
    int B[10];
    int size = sizeof(A)/sizeof(A[0]);

    printf("Original Array:\n");
    printArray(A, size-1);

    split(A, B, 0, size-1);
    printf("Sorted array: \n");
    printArray(B, size-1);
};
