// Problem: Implement push and pop operations on a stack and verify stack operations.

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Initialize stack
void initStack(Stack* s) {
    s->top = -1;
}

// Push operation
void push(Stack* s, int val) {
    if (s->top == MAX - 1) return; // Stack Overflow
    s->items[++(s->top)] = val;
}

// Pop operation
void pop(Stack* s) {
    if (s->top == -1) return; // Stack Underflow
    s->top--;
}

int main() {
    int n, m, val;
    Stack s;
    initStack(&s);
    printf("Enter the number of elements to push: ");
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        push(&s, val);
    }

    printf("Enter the number of elements to pop: ");
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        pop(&s);
    }

    for (int i = s.top; i >= 0; i--) {
        printf("%d%s", s.items[i], (i == 0) ? "" : " ");
    }
    printf("\n");

    return 0;
}