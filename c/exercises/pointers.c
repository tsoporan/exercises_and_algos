// Pointer fun?

#include <stdio.h>

int main(int argc, char* argv[]) {

    int i = 1, j = 2, k = 3;

    int* ip = &i;
    int* jp = &j;

    // Pointer to a pointer.
    int** ipp;

    // Points to address of int pointer ip
    ipp = &ip;

    printf("IPP VAL %d\n", **ipp);
    printf("IP VAL %d\n", *ip);

    *jp = 5;

    printf("JP VAL %d\n", *jp);
    printf("J VAL %d\n", j);

    ipp = &jp;
    **ipp = 3;

    *ipp = &i;

    printf("IPP VAL %d\n", **ipp);
    printf("J VAL %d\n", j);

    // ---------

    char name[] = "Alice";
    char* names[] = {
        "Alice", "Bob"
    };

    char* c;
    char** cpp;

    cpp = names;
    c = name;

    printf("Char at 0: %c\n", c[0]);
    printf("String at 0: %s\n", cpp[0]);

    *cpp = name;

    printf("String at 0: %c\n", *cpp[0]);

    return 0;
}
