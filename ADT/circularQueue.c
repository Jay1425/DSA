#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularQueue *q)
{
    if(q->f==q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q)
{
    if((q->r+1)%q->size==q->f)
    {
        return 1;
    }
    return 0;
}

void traversal(struct circularQueue * q)
{
    
    if(isEmpty(q))
    {
        printf("queue is empty\n");
    }
    else
    {
        int i = (q->f+1)%q->size;
        while(i!=(q->r+1)%q->size)
        {
            printf("%d ", q->arr[i]);
            i = (i+1)%q->size;
        }
    }

}
void enqueue(struct circularQueue *q, int val)
{
    if(isFull(q))
    {
        printf("queue is full\n");
    }
    else
    {
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct circularQueue *q)
{
    int val = -1;
    if(isEmpty(q))
    {
        printf("queue is empty");
    }
    else
    {
        q->f = (q->f+1)%q->size;
        val = q->arr[q->f];
    }
    return val;
}

int main()
{
    struct circularQueue q;
    q.size = 5;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size*sizeof(int));

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 10);

    traversal(&q);

    return 0;
}