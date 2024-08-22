#include <stdio.h>

void printArray(int* A, int n)
{
    for(int i=0; i<n;  i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int * A, int n)
{
    int indexOfMin, i, j, temp;
    for(i=0; i<n-1; i++)
    {
        indexOfMin = i;
        for(j=i+1; j<n; j++)
        {
            if(A[j]<A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main()
{
    int A[] = {8, 0, 2, 4, 1, 6};
    int n = 6;

    printf("before sorting\n");
    printArray(A, n);

    selectionSort(A, n);

    printf("after sorting\n");
    printArray(A, n);

    return 0;
}