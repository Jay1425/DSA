#include <stdio.h>
#include <stdlib.h>

struct Node * f = NULL;
struct Node * r = NULL;

struct Node
{
    int data;
    struct Node * next;
};

void traversal()
{
    struct Node * p = f;
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void enqueue(int val)
{
    struct Node * n = (struct Node*)malloc(sizeof(struct Node));
    if(n==NULL)
    {
        printf("queue is full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if(f==NULL)
        {
            f=r=n;
        }
        else
        {
            r->next = n;
            r=n;
        }
    }
}

int dequeue()
{
    struct Node * ptr = f;
    int val = -1;
    if(f==NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        ptr = f;
        f = f->next;
        val = ptr->data;
    }
    return val;
    free(ptr);
}

int main()
{
    printf("queue before : \n");
    traversal();

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("queue after : \n");
    traversal();

    return 0;
}