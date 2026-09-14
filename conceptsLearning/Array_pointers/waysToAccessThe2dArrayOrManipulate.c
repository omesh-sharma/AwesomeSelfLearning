#include <stdio.h>

void demonstrateArrayAccess(int **arr, int numRows, int numCols) {
    // Accessing elements using array notation
    printf("Array Notation:\n");
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            printf("Element at [%d][%d]: %d\n", i, j, arr[i][j]);
        }
    }
    
    // Accessing elements using pointer arithmetic
    printf("\nPointer Arithmetic:\n");
    for (int i = 0; i < numRows; ++i) {
        int *rowPtr = *(arr + i); // Pointer to the i-th row
        for (int j = 0; j < numCols; ++j) {
            printf("Element at [%d][%d]: %d\n", i, j, *(rowPtr + j));
        }
    }

    // Using pointer increment
    printf("\nPointer Increment:\n");
    int **ptr = arr;  // Pointer to the first row
    printf("Initial value at [0][0]: %d\n", **ptr);
    ++ptr;            // Move to the next row
    printf("Value at the next row's [0][0]: %d\n", **ptr);

    // Using pointer decrement
    printf("\nPointer Decrement:\n");
    --ptr;            // Move back to the original row
    printf("Back to the original value at [0][0]: %d\n", **ptr);

    // Decrementing values using --*arr and --**arr
    printf("\nDecrementing Values:\n");
    --*arr;           // Decrement the first element of the first row
    printf("After --*arr, updated value at [0][0]: %d\n", **arr);

    --**arr;          // Decrement the value at arr[0][0] directly
    printf("After --**arr, updated value at [0][0]: %d\n", **arr);
}

int main() {
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    int row3[] = {7, 8, 9};
    
    int *arr[] = {row1, row2, row3}; // Array of pointers to rows

    int numRows = sizeof(arr) / sizeof(arr[0]);
    int numCols = sizeof(row1) / sizeof(row1[0]);

    demonstrateArrayAccess(arr, numRows, numCols);

    return 0;
}
