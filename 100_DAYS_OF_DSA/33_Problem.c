// Problem: Convert an infix expression to postfix notation using stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

void infixToPostfix(char* exp) {
    int n = strlen(exp);
    char stack[n];
    int top = -1;
    char result[n + 1];
    int k = 0;

    for (int i = 0; i < n; i++) {
        char c = exp[i];

        if (isalnum(c)) {
            result[k++] = c;
        }
        else if (c == '(') {
            stack[++top] = c;
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                result[k++] = stack[top--];
            }
            top--;
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                result[k++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    while (top != -1) {
        result[k++] = stack[top--];
    }

    result[k] = '\0';
    printf("%s\n", result);
}

int main() {
    char exp[100];
    printf("Enter an infix expression: ");
    if (scanf("%s", exp) == 1) {
        infixToPostfix(exp);
    }
    return 0;
}