#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue * q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue * q)
{
    if(q->f==q->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue * q, int val)
{
    if(isFull(q))
    {
        printf("queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue * q)
{
    int a = -1;
    if(isEmpty(q))
    {
        printf("queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
        return a;
    }
}

void traversal(struct queue * q)
{
    
    if(isEmpty(q))
    {
        printf("queue is empty\n");
    }
    else
    {
        for(int i=q->f+1; i<=q->r; i++)
        {
            printf("%d ", q->arr[i]);
        }
    }

}

void main()
{
    struct queue q;
    q.size = 5;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    traversal(&q);


}