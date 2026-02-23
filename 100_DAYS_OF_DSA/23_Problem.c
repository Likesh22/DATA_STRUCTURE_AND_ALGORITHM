// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1 != NULL) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}

int main() {
    int n, m, val;
    struct Node *list1 = NULL, *list2 = NULL, *tail = NULL;
    printf("Enter the number of elements in list 1: ");
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            printf("Enter element for list 1: ");
            scanf("%d", &val);
            struct Node* newNode = createNode(val);
            if (!list1) list1 = tail = newNode;
            else { tail->next = newNode; tail = newNode; }
        }
    }
    tail = NULL;
    printf("Enter the number of elements in list 2: ");
    if (scanf("%d", &m) == 1) {
        for (int i = 0; i < m; i++) {
            printf("Enter element for list 2: ");
            scanf("%d", &val);
            struct Node* newNode = createNode(val);
            if (!list2) list2 = tail = newNode;
            else { tail->next = newNode; tail = newNode; }
        }
    }

    struct Node* mergedHead = mergeLists(list1, list2);
    struct Node* temp = mergedHead;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL) ? "" : " ");
        temp = temp->next;
    }
    printf("\n");
    return 0;
}