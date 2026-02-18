// WAP to covert Infix expression into Postix expression using stack

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;
void push(int item) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    top = top + 1;
    stack[top] = item;
}
int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
void fix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') {
        if (ch >= '0' && ch <= '9') {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    fix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
