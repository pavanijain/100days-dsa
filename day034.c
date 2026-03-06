#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

// Push function
void push(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

// Pop function
int pop()
{
    struct node *temp;
    int value;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    temp = top;
    value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

// Evaluate postfix expression
int evaluate(char exp[])
{
    int i = 0, a, b, result;

    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            b = pop();
            a = pop();

            switch(exp[i])
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        i++;
    }

    return pop();
}

int main()
{
    char exp[50];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    int ans = evaluate(exp);

    printf("Result = %d", ans);

    return 0;
}