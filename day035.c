#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *front = NULL;
Node *rear = NULL;
void enqueue(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
void display()
{
    Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        enqueue(value);
    }
    display();
    return 0;
}