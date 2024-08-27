#include <stdio.h>
#include <stdlib.h>

struct Node * f = NULL;
struct Node * r = NULL;

struct Node
{
    int data;
    struct Node * next;
    struct Node * prev;
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

void enqueueR(int val)
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
        n->prev = r;
        if(f==NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }

}

void enqueueF(int val)
{
    struct Node * n = (struct Node*)malloc(sizeof(struct Node));
    if(n==NULL)
    {
        printf("queueis full");
    }
    else
    {
        n->data = val;
        n->next = f;
        n->prev = NULL;
        if(f==NULL)
        {
            f = r = n;
        }
        else
        {
            f->prev = n;
            f = n;
        }
    }
}

int dequeueF()
{
    struct Node * ptr = f;
    int val = -1;
    if(f==NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        val = ptr->data;
        f = f->next;
        f->prev = NULL;
    }
    return val;
    free(ptr);
}

int dequeueR()
{
    struct Node * ptr = r;
    int val = -1;
    if(f==NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        val = ptr->data;
        r = r->prev;
        r->next = NULL; 
    }
    return val;
    free(ptr);
}

int main()
{
    enqueueR(10);
    enqueueF(20);
    enqueueF(30);
    enqueueR(40);

    printf("before :\n");
    traversal();

    dequeueF();
    dequeueR();

    printf("after :\n");
    traversal();

    return 0;
}