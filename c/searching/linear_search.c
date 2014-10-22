// Determines if a target number exists in an unsorted list, c99.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int search(int *numArray, int target, int arrLen) {

    for (int i = 0; i < arrLen - 1; i++) {
        if (numArray[i] == target) {
            return 1;
        }

        // If the list was sorted we could short circuit at this point
        // by numArray[i] > target : return -1
    }

    return -1;
}

void print_list(int *numArray, int arrLen) {

    for (int i = 0; i < arrLen - 1; i++) {
        printf("%d\n", numArray[i]);
    }
}

int main() {
    int arrSize = 10;
    int numbers[arrSize];

    // Seed with timestamp.
    srand(time(0));

    for (int i = 0;  i < 10; i++) {
        numbers[i] = rand() % 20; // Range up to 20.
    }

    print_list(numbers, 10);

    printf("Searching for n=5: %d\n",  search(numbers, 5,  arrSize) );
    printf("Searching for n=10: %d\n", search(numbers, 10, arrSize) );
    printf("Searching for n=15: %d\n", search(numbers, 15, arrSize) );
}

