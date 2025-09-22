#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

struct Node* reverseList(struct Node* headRef) {
    struct Node* prev = NULL;
    struct Node* curr = headRef;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome() {
    if (head == NULL || head->next == NULL)
        return true;
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* secondHalf = reverseList(slow->next);

    struct Node* firstHalf = head;
    struct Node* temp2 = secondHalf;
    bool palindrome = true;

    while (temp2 != NULL) {
        if (firstHalf->data != temp2->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp2 = temp2->next;
    }

    slow->next = reverseList(secondHalf);

    return palindrome;
}

void display() {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(value);
    }

    display();

    if (isPalindrome())
        printf("The linked list is a Palindrome.\n");
    else
        printf("The linked list is NOT a Palindrome.\n");

    return 0;
}
