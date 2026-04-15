//Q:finds the missing number from an array.
#include <stdio.h>

int main() {
    int n, missing = -1;

    printf("Enter N: ");
    scanf("%d", &n);

    int arr[n - 1];

    printf("Enter %d elements:\n", n - 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= n; i++) {
        int found = 0;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] == i) {
                found = 1;
                break;
            }
        }
        if (!found) {
            missing = i;
            break;
        }
    }

    printf("Missing Number = %d\n", missing);

    return 0;
}

// Q2: Given a mountain array, find the peak index and sort in increasing order.
// Example: arr={1,3,5,7,6,4,2} => Peak index=3, Sorted={1,2,3,4,5,6,7}
// Time Complexity: O(n) | Space Complexity: O(1)

#include <stdio.h>

int findPeak(int arr[], int n) {
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            return i;
    }
    return -1;
}

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void sortMountain(int arr[], int n, int peak) {
    reverse(arr, 0, peak);        // reverse left half
    reverse(arr, peak + 1, n - 1); // reverse right half
    reverse(arr, 0, n - 1);       // reverse whole array
}

int main() {
    int arr[] = {1, 3, 5, 7, 6, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peak = findPeak(arr, n);
    printf("Peak Index: %d => Value: %d\n", peak, arr[peak]);

    sortMountain(arr, n, peak);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
