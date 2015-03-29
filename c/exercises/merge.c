/* Merging two arrays that are assumed sorted ascending. */

#include <stdio.h>
void printArray(int* arr, int size);
void mergeArrays(int* A, int* B, int* C, int sizeA, int sizeB);

void mergeArrays(int* A, int* B, int* C,  int sizeA, int sizeB) {

    int i = 0, j = 0, k = 0;

    sizeA = sizeA - sizeB;

    // Compare arrays.
    while(i < sizeA && j < sizeB) {
        if (A[i] < B[j]) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];
            j++;
        }
        k++;
    }

    // Add remainders.
    for (; i < sizeA; i++) {
        C[i + j] = A[i];
    }

    for (; j < sizeB; j++) {
        C[i + j] = B[j];
    }

}

void printArray(int* A, int size) {
    for (int k = 0; k < size; k++) {
        printf("%i,",  A[k]);
    }
    printf("\n");
}

int main() {

    int A[6] = {1,2,3,0,0,0};
    int B[3] = {0,1,2};
    int C[6];

    int sizeA = sizeof(A)/sizeof(A[0]);
    int sizeB = sizeof(B)/sizeof(B[0]);

    printf("Original A array, size=%i:\n", sizeA);
    printArray(A, sizeA);
    printf("Original B array, size=%i:\n", sizeB);
    printArray(B, sizeB);

    mergeArrays(A, B, C, sizeA, sizeB);

    printf("Merged array:\n");
    printArray(C, sizeA);
}
