#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * Traversal(struct Node * ptr)
{

    while(ptr!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * deleteFirst(struct Node * head)
{
    struct Node * p = head;
    head = head->next;
    free(p);
    return head;
}

struct Node * deleteMiddle(struct Node * head, int index)
{
    struct Node * p =head;
    struct Node * q = head->next;
    for(int i=0; i<index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node * deleteLast(struct Node * head)
{
    struct Node * p =head;
    struct Node * q = head->next;
    while(q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node * deleteValue(struct Node * head, int value)
{
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data!=value && q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data==value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    struct Node * fifth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;

    printf("list before deletion :\n");
    Traversal(head);

    //head = deleteFirst(head);
    //head = deleteMiddle(head, 2);
    //head = deleteLast(head);
    head = deleteValue(head, 30);

    printf("list after deletion :\n");
    Traversal(head);
    return 0;
}