#include <stdio.h>

int main()
{
    int n, m, i;

    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &m);

    int front = 0;
    int rear = n - 1;

   
    for(i = 0; i < m; i++)
        front = (front + 1) % n;

    
    int count = 0;
    i = front;

    while(count < n)
    {
        printf("%d ", arr[i]);
        i = (i + 1) % n;
        count++;
    }

    return 0;
}