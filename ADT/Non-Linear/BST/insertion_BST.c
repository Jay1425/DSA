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
    struct node * n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(struct node * root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void insert(struct node * root, int key)
{
    struct node * prev = NULL;

    while (root != NULL)
    {
        prev = root;

        if (key == root->data)
        {
            printf("Key already exists.\n");
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    struct node * n = createNode(key);

    if (key < prev->data)
    {
        prev->left = n;
    }
    else
    {
        prev->right = n;
    }
}

int main()
{

     /*      12
           /   \
          3     15
         / \    / \
        1   7  13  17
           / \
          6  10
     */
    struct node * p1 = createNode(12);
    struct node * p2 = createNode(3);
    struct node * p3 = createNode(15);
    struct node * p4 = createNode(1);
    struct node * p5 = createNode(7);
    struct node * p6 = createNode(13);
    struct node * p7 = createNode(17);
    struct node * p8 = createNode(6);
    struct node * p9 = createNode(10);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p5->left = p8;
    p5->right = p9;

    p3->left = p6;
    p3->right = p7;

    insert(p1, 2);

    printf("Inorder traversal after insertion: ");
    inOrder(p1);
    
    return 0;
}