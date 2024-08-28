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

struct node * search(struct node * root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return root;
    }
    else if(root->data>key)
    {
        search(root->left, key);
    }
    else
    {
        search(root->right, key);        
    }
}

int main()
{
     /*          10
               /    \
              2      12
             / \     / \
            1   4   11  14
               / \      / \
              3   8    13  15
                 / \
                6   9
               / \ 
              5   7
     */
    struct node * p1 = createNode(10);
    struct node * p2 = createNode(2);
    struct node * p3 = createNode(12);
    struct node * p4 = createNode(1);
    struct node * p5 = createNode(4);
    struct node * p6 = createNode(11);
    struct node * p7 = createNode(14);
    struct node * p8 = createNode(3);
    struct node * p9 = createNode(8);
    struct node * p10= createNode(13);
    struct node * p11 = createNode(15);
    struct node * p12 = createNode(6);
    struct node * p13 = createNode(9);
    struct node * p14 = createNode(5);
    struct node * p15 = createNode(7);

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;
    p5->left = p8;
    p5->right = p9;
    p9->left = p12;
    p9->right = p13;
    p12->left = p14;
    p12->right = p15;

    p3->left = p6;
    p3->right = p7;
    p7->left = p10;
    p7->right = p11;

    //printf("%d\n", isBST(p1));
    struct node * a = search(p1, 7);
    if(a!=NULL)
    {
        printf("Found Element : %d\n", a->data);
    }
    else
    {
        printf("Element Not Found\n");
    }
    
    return 0;
}