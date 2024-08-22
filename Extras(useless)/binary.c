#include <stdio.h>

int main()
{
    int n, low=0, mid, high=4, key, flag=0;

    int s[5]={10,20,30,40,50};
   
    printf("\nenter key value : ");
    scanf("%d", &key);
    while(low<=high)
    {
        mid = (low+high)/2;
        if(s[mid]==key)
        {
            printf("\nkey found at %d index", mid);
            flag++;
            break;
        }
        else if(s[mid]<key)
        {
            low=mid+1;
        }
        else if(s[mid]>key)
        {
            high=mid-1;
        }
    }
    if(flag==0)
    {
        printf("\nkey not found");
    }

}