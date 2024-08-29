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
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct node * inOrderPredecessor(struct node * root)
{
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
    
}

struct node * deleteNode(struct node * root, int val)
{
    struct node * iPre;
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }

    if(val<root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else if(val>root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
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


    printf("inorder traversal before :\n");
    inOrder(p1);
    printf("\n");

    deleteNode(p1,7);

    printf("inorder traversal after :\n");
    inOrder(p1);

    return 0;
}