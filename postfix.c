#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max 100

char stack[max];
int top = -1;

void push(char c)
{
    if (top == max - 1)
        printf("Stack overflow\n");
    else
        stack[++top] = c;
}

char peek()
{
    if (top == -1)
        return '\0';
    return stack[top];
}

char pop()
{
    char val;
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        val = stack[top--];
        return val;
    }
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, k = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        if (isalnum(c))
        {
            postfix[k++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[k++] = pop();
            }
            pop();
        }
        else
        {
            while (top != -1 && precedence(peek()) >= precedence(c))
            {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while (top != -1)
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main()
{
    char infix[max], postfix[max];

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
