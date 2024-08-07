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
struct Node * insertionAtbegin(struct Node * head, int data)
{
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct Node * insertionAtindex(struct Node * head, int data, int index)
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
    ptr->next = p->next;
    p->next = ptr;
    return head;

}
struct Node * insertionAtend(struct Node * head, int data)
{
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node * p = head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    p -> next = ptr;
    return head;
}
struct Node * insertionAfternode(struct Node * head, int data, struct Node * Q)
{
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = Q->next;
    Q->next = ptr;
    return head;
}
int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    printf("list before :\n");
    Traversal(head);
    printf("list after :\n");
    //head = insertionAtbegin(head, 50);
    //head = insertionAtmiddle(head, 50, 1);
    //head = insertionAtend(head, 50);
    head = insertionAfternode(head, 50, second);
    Traversal(head);

    return 0;
}