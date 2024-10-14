#include <stdio.h>
int evaluatePostfix(char* postfix)
{
    int stack[100];
    int top = -1; 
    int i = 0;
    while (postfix[i] != '\0') {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            stack[++top] = postfix[i] - '0';
        } else if (postfix[i] == ' ') {
            i++;
            continue;
        } else {
            int op2 = stack[top--];
            int op1 = stack[top--];
            switch (postfix[i]) {
                case '+':
                    stack[++top] = op1 + op2;
                    break;
                case '-':
                    stack[++top] = op1 - op2;
                    break;
                case '*':
                    stack[++top] = op1 * op2;
                    break;
                case '/':
                    stack[++top] = op1 / op2;
                    break;
            }
        }
        i++;
    }
    return stack[top];
}
int main() {
    char postfix[100];
    printf("Enter postfix expression: ");
    fgets(postfix, 100, stdin);
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}
