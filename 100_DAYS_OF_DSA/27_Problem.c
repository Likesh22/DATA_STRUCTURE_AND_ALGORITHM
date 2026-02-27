// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int l1 = getLength(head1);
    int l2 = getLength(head2);
    int d = abs(l1 - l2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    if (l1 > l2) {
        for (int i = 0; i < d; i++) ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < d; i++) ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {

        if (ptr1->data == ptr2->data) { 
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL;
    printf("Enter number of elements in first list: ");
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            printf("Enter element %d: ", i + 1);
            scanf("%d", &val);
            struct Node* newNode = createNode(val);
            if (!head1) head1 = tail1 = newNode;
            else { tail1->next = newNode; tail1 = newNode; }
        }
    }
    printf("Enter number of elements in second list: ");
    if (scanf("%d", &m) == 1) {
        for (int i = 0; i < m; i++) {
            printf("Enter element %d: ", i + 1);
            scanf("%d", &val);
            struct Node* newNode = createNode(val);
            if (!head2) head2 = tail2 = newNode;
            else { tail2->next = newNode; tail2 = newNode; }
        }
    }

    struct Node* intersect = findIntersection(head1, head2);

    if (intersect) printf("%d\n", intersect->data);
    else printf("No Intersection\n");

    return 0;
}