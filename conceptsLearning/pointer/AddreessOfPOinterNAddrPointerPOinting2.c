#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr;    // Declare a pointer to int

    ptr = arr;   // Assign the address of arr[0] to ptr

    // Print addresses
    printf("Address of ptr: %p\n", (void *)&ptr);    // Address of ptr itself
    printf("Address ptr points to: %p\n", (void *)ptr);  // Address that ptr points to (address of arr[0])

    return 0;
}
