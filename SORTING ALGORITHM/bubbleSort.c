#include <stdio.h>

//for adaptive version of bubble sort uncomment all comments from below

void printArray(int* A, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int* A, int n)
{
    int temp;
    //int isSorted = 0;
    for(int i=0; i<n-1; i++)
    {
        //printf("working on pass no : %d\n", i+1);
        //isSorted = 1;
        for(int j=0; j<n-1-i; j++)
        {
            if(A[j]>A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                //isSorted = 0;
            }
        }
        /*if(isSorted)
        {
            return;
        }*/
 
    }
}

int main()
{
    int A[] = {99, 1, 5, 2, 11, 3};
    //int A[] = {1, 2, 3, 4, 5, 6};

    int n = 6;

    printf("before sorting :\n");
    printArray(A, n);

    bubbleSort(A, n);

    printf("after sorting :\n");
    printArray(A, n);

    return 0;
}