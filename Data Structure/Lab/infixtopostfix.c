#include <stdio.h>
char stack[100];
int top = -1;

void push(char c) 
{
    if (top < 100 - 1)
    {
        stack[++top] = c;
    }
}
char pop()
{
    if (top != -1)
    {
        return stack[top--];
    }
    return '\0';
}
int precedence(char c)
{
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
void infixToPostfix(const char *infix, char *postfix)
{
    int i = 0, j = 0;
    while (infix[i]!='\0')
    {
        if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9'))
	{
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main()
{
    char infix[100], postfix[100];
    printf("Enter The Infix expression: ");
    scanf("%s",infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

