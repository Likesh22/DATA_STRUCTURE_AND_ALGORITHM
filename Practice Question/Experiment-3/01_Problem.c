// WAP to implement a stack data structure using an array

# include <stdio.h>
#define MAX 50

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

int pop(){
    if (top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

void peek() {
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

void display() {
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(5);
    push(10);
    push(15);
    push(20);
    push(25);

    display();

    peek();

    printf("Popped element: %d\n", pop());
   
    display();

    return 0;
}