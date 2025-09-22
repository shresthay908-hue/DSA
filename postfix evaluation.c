#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int evaluatePostfix(char exp[]) {
    int i, op1, op2;

    for (i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (isdigit(c)) {
            push(c - '0');
        }

        else {
            op2 = pop();
            op1 = pop();
            switch (c) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '^': push(pow(op1, op2)); break;
                default:
                    printf("Invalid operator %c\n", c);
                    return -1;
            }
        }
    }

    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result: %d\n", result);

    return 0;
}
