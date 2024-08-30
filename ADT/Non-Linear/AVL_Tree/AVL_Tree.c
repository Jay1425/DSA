#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node * left;
    struct Node * right;
    int height;
};

struct Node * createNode(int key)
{
    struct Node * n = (struct Node*)malloc(sizeof(struct Node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int max(int a, int b)
{
    return a>b?a:b;
}

int getHeight(struct Node * n)
{
    if(n==NULL)
    {
        return 0;
    }
    return n->height;
}

int getBalanceFactor(struct Node * n)
{
    if(n==NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct Node * leftRotate(struct Node * x)
{
    struct Node * y = x->right;
    struct Node * T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct Node * rightRotate(struct Node * y)
{
    struct Node * x = y->left;
    struct Node * T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return x;
}

struct Node * insert(struct Node * node, int key)
{
    if(node==NULL)
    {
        return createNode(key);
    }

    if(key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if(key > node->key)
    {
        node->right = insert(node->right, key);
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int bf = getBalanceFactor(node);

    //left-left
    if(bf>1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    //right-right
    if(bf<-1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    //left-right
    if(bf>1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //right-left
    if(bf<-1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrder(struct Node * node)
{
    if(node!=NULL)
    {
        inOrder(node->left);
        printf("%d ", node->key);
        inOrder(node->right);
    }
}

void preOrder(struct Node * node)
{
    if(node!=NULL)
    {
        printf("%d ", node->key);
        preOrder(node->left);
        preOrder(node->right);
    }
}

int main()
{
    struct Node * root = NULL;

    root = insert(root, 5);
    root = insert(root, 9);
    root = insert(root, 20);
    root = insert(root, 16);
    root = insert(root, 12);
    root = insert(root, 15);
    root = insert(root, 21);
    root = insert(root, 2);

    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");

    return 0;

}