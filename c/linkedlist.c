// An implementation of a single linked-list.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {

    // Create the head node.
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current = (struct Node*)malloc(sizeof(struct Node));

    head->data = 0;
    head->next = NULL;

    current = head;

    for (int i = 1; i <= 10; i ++) {

        // Create new node.
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = NULL;

        // Set current node to newNode.
        current->next = newNode;
        current = newNode;
    }

    // Iterate over nodes from head.
    while (head != NULL) {
        printf("Node data: %d\n", head->data);
        head = head->next;
    }

    return 0;

}
