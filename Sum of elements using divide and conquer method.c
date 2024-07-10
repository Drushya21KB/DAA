#include <stdio.h>

// Function to find the sum of elements in an array (Divide and Conquer method)
int sumDivideConquer(int arr[], int l, int r) {
    if (l == r) {
        return arr[l]; // Base case: single element
    } else {
        int m = (l + r) / 2;
        // Divide the array into two halves and recursively find sum
        int leftSum = sumDivideConquer(arr, l, m);
        int rightSum = sumDivideConquer(arr, m + 1, r);
        // Combine the results
        return leftSum + rightSum;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = sumDivideConquer(arr, 0, n - 1);
    printf("Sum of elements (Divide and Conquer method): %d\n", result);

    return 0;
}
