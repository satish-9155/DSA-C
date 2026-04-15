//Binary search

#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n, key, i, result;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, n, key);

    if (result == -1)
        printf("Element not found");
    else
        printf("Element found at position %d", result + 1);

    return 0;
}
