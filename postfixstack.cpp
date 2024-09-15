#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function to check if a character is a digit
int isOperand(char item) {
    return isdigit(item);
}

// Function to push an item onto the stack
void push(int item) {
    stack[++top] = item;
}

// Function to pop an item from the stack
int pop() {
    return stack[top--];
}

// Function to evaluate an operation
int evaluate(int a, int b, char opr) {
    switch(opr) {
        case '^': return pow(a, b);
        case '*': return a * b;
        case '/': return a / b;
        case '+': return a + b;
        case '-': return a - b;
        default: printf("Invalid operator\n"); exit(1);
    }
}

// Function to check if a character is an operator
int isOperator(char item) {
    return (item == '+' || item == '-' || item == '*' || item == '/' || item == '^');
}

int main() {
    char expression[MAX] = "3 2 5 2 ^ * -";
    int i = 0, a, b, c, result;
    char opr;

    while(expression[i] != '\0') {
        
        if (isOperand(expression[i])) {
            // Push the operand (convert char to int)
            push(expression[i] - '0');
        } else if (isOperator(expression[i])) {
            // Pop two operands for the operator
            b = pop();
            a = pop();
            opr = expression[i];
            // Evaluate the expression and push the result
            c = evaluate(a, b, opr);
            push(c);
        }

        i++;
    }

    // Get the result
    result = pop();
    printf("Value of postfix expression is %d\n", result);

    return 0;
}
