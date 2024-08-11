#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node * Traverse(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node * InsertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = head;
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = p;
    p->next = head;
    head = p;

    return head;
}

struct Node * InsertAtIndex(struct Node *head, int index, int data)
{
    struct Node *ptr = head;
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;

    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    p->next = ptr->next;
    ptr->next = p;

    return head;
}

struct Node * InsertAtEnd(struct Node *head, int data)
{
    struct Node * ptr = head;
    struct Node * p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = p;
    p->next = head;

    return head;
}

int main()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fifth;

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
    fifth->next = head;

    printf("Circular Linked List before :\n");
    Traverse(head);

    //head = InsertAtFirst(head, 60);
    //head = InsertAtIndex(head, 2, 60);
    head = InsertAtEnd(head, 60);

    printf("Circular Linked List after :\n");
    Traverse(head);

    return 0;
}