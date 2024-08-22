#include <stdio.h>
#define n 5

int s[n];
int top = -1;

int push(int val)
{
    if(top==n-1)
    {
        printf("\nSTACK OVERFLOW");
    }
    else
    {
        ++top;
        s[top] = val;
        return s[top];
    }
}
int pop()
{
    if(top==-1)
    {
        printf("\nstack underflow");
        return -1;
    }
    else
    {
        return s[top--];
    }
}
int display()
{
    int value;
    if(top==-1)
    {
        printf("\n----stack is empty----");
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            value = s[i];
            printf("\n%d", value);
        }
    }
}
int peek()
{
    int vals;
    if(top==-1)
    {
        printf("\n----stack is empty----");
    }
    else
    {
        vals = s[top];
        printf("\nthe top value of stack is %d",vals);
    }
}
int main()
{
    int ch, val, popval;
    printf("\n1. PUSH");
    printf("\n2. POP");
    printf("\n3. DISPLAY");
    printf("\n4. PEEK");
    printf("\n5. EXIT");
  
    while(1)
    {
        printf("\nEnter Value : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter Value To Push : ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
        
                popval = pop();
                printf("\n%d is pop value", popval);
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
            default:
        }
    }
    
}