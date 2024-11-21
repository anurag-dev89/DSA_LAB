#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int cal(char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            push(expr[i] - '0');  // Convert char to int
        } else {
            int b = pop();
            int a = pop();
            switch (expr[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '%': push(a % b); break;
                case '^': push(pow(a, b)); break;
            }
        }
    }
    return pop();
}

int main() {
    char expr[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", expr);
    printf("Result: %d\n", cal(expr));
    return 0;
}
