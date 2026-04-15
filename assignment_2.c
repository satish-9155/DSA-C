// Insertion Short
#include <stdio.h>
void BinarySearch(int arr[],int item,int low, int high){
    while (low<=high)
    {
        int mid = (low + high)/2;
        if (item == arr[mid])
        {
            return mid+1;
        }
        else if (item > arr[mid] )
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }

    }
    return low;
}
void InsertionShorting(int arr[], int n){
    int i, j, key, loc;

    for (i = 1; i < n; i++) {
        key = arr[i];
        loc = binarySearch(arr, key, 0, i - 1);
        j = i - 1;
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    InsertionShorting(arr, n);
    printArray(arr, n);
    return 0;
}



// Merge Short
#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int *b, int *c, int m, int n)
{
    int i = 0, j = 0, k = 0, p;

    while ((i < m) && (j < n))
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    if (i == m)
    {
        for (p = j; p < n; p++)
        {
            c[k] = b[p];
            k++;
        }
    }
    else
    {
        for (p = i; p < m; p++)
        {
            c[k] = a[p];
            k++;
        }
    }
}

void merge_sort(int *A, int n)
{
    int i, j, k, m;
    int *B, *C;

    if (n > 1)
    {
        k = n / 2;
        m = n - k;

        B = (int *)malloc(k * sizeof(int));
        C = (int *)malloc(m * sizeof(int));

        for (i = 0; i < k; i++)
            B[i] = A[i];

        for (j = k; j < n; j++)
            C[j - k] = A[j];

        merge_sort(B, k);
        merge_sort(C, m);

        merge(B, C, A, k, m);

        free(B);
        free(C);
    }
}

int main()
{
    int A[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(A) / sizeof(A[0]);
    int i;

    merge_sort(A, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
