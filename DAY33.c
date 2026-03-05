#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Push operation */
void push(char x) {
    stack[++top] = x;
}

/* Pop operation */
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

/* Return precedence of operators */
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

/* Convert infix to postfix */
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;

    while (infix[i] != '\0') {
        ch = infix[i];

        /* If operand, add to postfix */
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        /* If '(', push to stack */
        else if (ch == '(') {
            push(ch);
        }
        /* If ')', pop until '(' */
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        }
        /* Operator */
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }

        i++;
    }

    /* Pop remaining operators */
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}
