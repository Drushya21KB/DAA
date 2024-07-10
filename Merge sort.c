#include <stdio.h>
#include <stdlib.h> // for malloc and free

// Function to merge two sorted subarrays A[l..m] and A[m+1..r] into A[l..r]
void merge(int A[], int l, int m, int r) {
    int n1 = m - l + 1; // Size of left subarray
    int n2 = r - m;     // Size of right subarray

    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    // Merge the temporary arrays back into A[l..r]
    int i = 0; // Initial index of left subarray
    int j = 0; // Initial index of right subarray
    int k = l; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        A[k++] = L[i++];
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        A[k++] = R[j++];
    }

    // Free dynamically allocated memory
    free(L);
    free(R);
}

// Function to implement merge sort on array A[l..r]
void mergeSort(int A[], int l, int r) {
    if (l < r) {
        // Find the middle point
        int m = l + (r - l) / 2;

        // Recursive calls to mergeSort for left and right subarrays
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);

        // Merge the sorted subarrays
        merge(A, l, m, r);
    }
}

// Function to print the array
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(A) / sizeof(A[0]);

    printf("Given array is \n");
    printArray(A, arr_size);

    mergeSort(A, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(A, arr_size);

    return 0;
}
