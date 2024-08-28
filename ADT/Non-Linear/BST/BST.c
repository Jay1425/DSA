#include <stdio.h>
#include <malloc.h>

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

int isBST(struct node * root)
{
    static struct node * prev = NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    struct node * p = createNode(10);
    struct node * p2 = createNode(6);
    struct node * p3 = createNode(11);
    struct node * p4 = createNode(5);
    struct node * p5 = createNode(8);
    struct node * p6 = createNode(7);
    struct node * p7 = createNode(9);

     /*       10
              / \
             6  11
            / \
           5   8
              / \
             7   9
     */
    p->left = p2;
    p->right = p3;
    p2->left = p4;
    p2->right = p5;
    p5->left = p6;
    p5->right = p7;

    printf("inOrder Traversal :\n");
    inOrder(p);
    printf("\n");

    int a = isBST(p);
    if(a)
    {
        printf("tree is Binary Search Tree.\n");
    }
    else
    {
        printf("tree is not  Binary Search Tree.\n");
    }

    return 0;
}