#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x) { stack[++top] = x; }
char pop() { return stack[top--]; }

int precedence(char ch) {
    return (ch == '+' || ch == '-') ? 1 : (ch == '*' || ch == '/') ? 2 : (ch == '(') ? 0 : -1;
}

void convert(char *exprn, char *postfix) {
    int j = 0;
    push('#');
    for (int i = 0; exprn[i] != '#'; i++) {
        char ch = exprn[i];
        if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop the '(' without adding to postfix
        } else if (strchr("+-*/", ch)) {
            while (precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        } else {
            postfix[j++] = ch;
        }
    }
    while (stack[top] != '#') {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char exprn[20], postfix[20];
    printf("Enter the infix expression (end with #): ");
    scanf("%s", exprn);
    strcat(exprn, "#");
    convert(exprn, postfix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}


