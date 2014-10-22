// Insertion sort on an Array, runs in O(n^2)

#include <stdio.h>
#include <stdlib.h>

void sort(int *values, int arrSize) {
    int j = 0;
    int temp;

    for (int i = 0; i <= arrSize - 1; i++) {

        for (int j = 0; j < i; j++) {
            if (values[j] > values[i]) {
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }

    }
}

void printList(int *arr, int arrSize) {
    for (int i = 0; i <= arrSize -1; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    int arr[10] = {1, 4, 3, 2, 0, 9, 6, 3, 5, 7};

    printf("Unsorted:\n");
    printList(arr, 10);

    sort(arr, 10);

    printf("Sorted:\n");
    printList(arr, 10);


}
