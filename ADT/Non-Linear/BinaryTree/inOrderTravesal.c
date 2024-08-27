#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createNode(int data)
{
    struct node * n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(struct node * root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    /*
            2
           / \
          7   5
         / \   \
        11  6   3
    */

    struct node * p = createNode(2);
    struct node * p2 = createNode(7);
    struct node * p3 = createNode(5);
    struct node * p4 = createNode(11);
    struct node * p5 = createNode(6);
    struct node * p6 = createNode(3);

    p->left = p2;
    p->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->right = p6;

    inOrder(p);
    //11 7 6 2 5 3
    return 0;
}