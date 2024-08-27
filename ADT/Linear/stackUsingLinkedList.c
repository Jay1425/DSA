#include <stdio.h>
#include <stdlib.h>

struct Node * top = NULL;

struct Node
{
    int data;
    struct Node * next;
};

int isEmpty(struct Node * top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node * top)
{
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node * push(struct Node * top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node * tp)
{
    if (isEmpty(tp))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node * n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int stackTop(struct Node * tp)
{
    return tp->data;
}

int stackBottom(struct Node * tp)
{
    struct Node * n = tp;
    while (n->next != NULL)
    {
        n = n->next;
    }
    return n->data;
}

int peek(struct Node * tp, int pos)
{
    struct Node * n = tp;
    for (int i = 0; (i < pos - 1 && n != NULL); i++)
    {
        n = n->next;
    }
    if (n != NULL)
    {
        return n->data;
    }
    else
    {
        return -1;
    }
}

int display(struct Node * tp)
{
    struct Node * n = tp;
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
        printf("\n");
    }
    
}

void main()
{
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. display\n");
    printf("4. Peek\n");
    printf("5. Stack Top\n");
    printf("6. Stack Bottom\n");
    printf("7. Exit\n");

    int choice, x, pos;

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &x);
            top = push(top, x);
            break;

        case 2:
            printf("Popped element is: %d\n", pop(top));
            break;

        case 3:
            display(top);
            break;  

        case 4:
            printf("Enter the position: ");
            scanf("%d", &pos);
            printf("Element at position %d is: %d\n", pos, peek(top, pos));
            break;

        case 5:
            printf("Element at top is: %d\n", stackTop(top));
            break;

        case 6:
            printf("Element at bottom is: %d\n", stackBottom(top));
            break;

        default:
            break;
        }
    } while (choice != 7);

}