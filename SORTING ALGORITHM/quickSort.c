#include <stdio.h>

void printArray(int * A, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int * A, int low, int high)
{
    int pivot = A[low];
    int i = low+1;
    int j = high;
    int temp;

    do
    {
        while(A[i]<=pivot)
        {
            i++;
        }
        while(A[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i<j);
    
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
    
}

void quickSort(int * A, int low, int high)
{
    int partitionIndex;

    if(low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex-1);
        quickSort(A, partitionIndex+1, high);
    }
}

int main()
{
    int A[] = {8, 13, 2, 4, 1, 6, 9, 18, 20, 3};
    int n = 10;

    printf("before sorting :\n");
    printArray(A, n);

    quickSort(A, 0, n-1);

    printf("after sorting :\n");
    printArray(A, n);

    return 0;
}