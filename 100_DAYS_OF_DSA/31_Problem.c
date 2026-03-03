// Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

void display() {
    if (top == -1) {
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0 ? "" : " "));
    }
    printf("\n");
}

int main() {
    int n, choice, value;
    printf("Enter the number of operations: ");
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        printf("Enter operation (1 for push, 2 for pop, 3 for display): ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            display();
        }
    }

    return 0;
}