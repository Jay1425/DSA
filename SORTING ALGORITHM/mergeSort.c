#include <stdio.h>
#include <stdlib.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int *A, int mid, int low, int high)
{
    int i = low, j = mid + 1, k = low;
    int B[100];
    
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (i = 0; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int *A, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    int A[] = {3, 9, 7, 5, 4, 6, 25, 11, 8, 1};
    int n = 10;

    printf("before sorting\n");
    printArray(A, n);

    mergeSort(A, 0, 9);

    printf("after sorting\n");
    printArray(A, n);

    return 0;
}