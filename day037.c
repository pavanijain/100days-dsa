#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element
void insert(int x)
{
    int i = size - 1;

    // Shift elements greater than x
    while(i >= 0 && pq[i] > x)
    {
        pq[i+1] = pq[i];
        i--;
    }

    pq[i+1] = x;
    size++;
}

// Delete highest priority element
void delete()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    for(int i = 1; i < size; i++)
        pq[i-1] = pq[i];

    size--;
}

// Peek highest priority element
void peek()
{
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", pq[0]);
}

int main()
{
    int n, x;
    char op[10];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(op[0] == 'i') // insert
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'd') // delete
        {
            delete();
        }
        else if(op[0] == 'p') // peek
        {
            peek();
        }
    }

    return 0;
}