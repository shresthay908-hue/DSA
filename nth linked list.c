#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct Node* getNthNode(int index) {
    struct Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        if (count == index)
            return temp;
        count++;
        temp = temp->next;
    }
    return NULL;
}

void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, value;

    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);

    display();

    printf("Enter the index of node to fetch (0-based): ");
    scanf("%d", &n);

    struct Node* result = getNthNode(n);
    if (result != NULL)
        printf("Node at index %d = %d\n", n, result->data);
    else
        printf("Index %d out of range.\n", n);

    return 0;
}
