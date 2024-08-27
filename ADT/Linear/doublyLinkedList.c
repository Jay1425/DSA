#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * prev;
    struct Node * next;
};

void Traverse(struct Node * head)
{
    struct Node * ptr = head;
    
    printf("Traverse Front\n");
    while(ptr->next!=NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
        
    }
    printf("Element is %d\n", ptr->data);

    printf("Traverse Back\n");
    while(ptr!=NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->prev;
    }
    
}

struct Node * InsertAtFirst(struct Node * head, int data)
{
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    return head;
}

struct Node * InsertAtIndex(struct Node * head, int data, int index)
{
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->prev = p;
    ptr->next = p->next;
    p->next->prev = ptr;
    p->next = ptr;
    return head;
}

struct Node * InsertAtEnd(struct Node * head, int data)
{
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node * p = head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->prev = p;
    ptr->next = NULL;
    p->next = ptr;
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
    head->prev = NULL;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = fourth;

    fourth->data = 40;
    fourth->prev = third;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->prev = fourth;
    fifth->next = NULL;

    printf("Before : \n");
    Traverse(head);

    head = InsertAtFirst(head, 60);
    //head = InsertAtIndex(head, 60, 2);
    //head = InsertAtEnd(head, 60);


    printf("After : \n");
    Traverse(head);


    return 0;
}
