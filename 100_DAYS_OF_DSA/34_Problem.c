// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return;
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) return 0;
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;
    char* token = strtok(exp, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        } 
        else {
            int b = pop(&stack);
            int a = pop(&stack);

            switch (token[0]) {
                case '+': push(&stack, a + b); break;
                case '-': push(&stack, a - b); break;
                case '*': push(&stack, a * b); break;
                case '/': push(&stack, a / b); break;
            }
        }
        token = strtok(NULL, " ");
    }
    return pop(&stack);
}

int main() {
    char exp[100];
    printf("Enter a postfix expression: ");
    if (fgets(exp, sizeof(exp), stdin)) {
        exp[strcspn(exp, "\n")] = 0;
        printf("%d\n", evaluatePostfix(exp));
    }
    return 0;
}