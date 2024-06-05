// Certainly! Here's a program that demonstrates iterating through an array of pointers (int* ptr[4]) where the pointers can point to both 2D arrays (int arr2D[3][4]) and 1D arrays (int arr1D[4]):
// c
// Copy code
#include <stdio.h>

int main() {
    // Define a 2D array and a 1D array
    int arr2D[3][4] = {{1, 2, 3, 4}, 
                       {5, 6, 7, 8}, 
                       {9, 10, 11, 12}};

    int arr1D[4] = {13, 14, 15, 16};

    // Define an array of pointers to int
    int* ptr[4];

    // Assign pointers to 2D arrays and 1D arrays to ptr
    ptr[0] = arr2D[0];
    ptr[1] = arr2D[1];
    ptr[2] = arr2D[2];
    ptr[3] = arr1D;

    // Iterate through ptr
    for (int i = 0; i < 4; i++) {
        // Accessing the pointer at index i
        int *currentPtr = ptr[i];

        // Check if the pointer points to a 2D array or a 1D array
        if (i < 3) {
            // Iterate through the elements of the 2D array pointed to by currentPtr
            for (int j = 0; j < 4; j++) {
                printf("%d ", currentPtr[j]);
            }
        } else {
            // Iterate through the elements of the 1D array pointed to by currentPtr
            for (int j = 0; j < 4; j++) {
                printf("%d ", currentPtr[j]);
            }
        }

        printf("\n");
    }

    return 0;
}
// In this program:
// We define a 2D array arr2D and a 1D array arr1D.
// We define an array of pointers ptr[4].
// We assign pointers to the first three elements of ptr to point to the three rows of arr2D, and we assign the fourth element of ptr to point to arr1D.
// We iterate through ptr, and for each pointer, we check if it points to a 2D array or a 1D array. Depending on that, we iterate through the elements of the array pointed to by the pointer and print them.





# POinter to array 

https://www.geeksforgeeks.org/pointer-array-array-pointer/

#include<stdio.h>

int main()
{
int arr[5] = { 1, 2, 3, 4, 5 };
int *ptr = arr;

printf("%p\n", ptr);
return 0;
}


// C program to understand difference between 
// pointer to an integer and pointer to an
// array of integers. 
#include<stdio.h>

int main()
{
	// Pointer to an integer
	int *p; 
	
	// Pointer to an array of 5 integers
	int (*ptr)[5]; 
	int arr[5];
	
	// Points to 0th element of the arr.
	p = arr;
	
	// Points to the whole array arr.
	ptr = &arr; 
	
	printf("p = %p, ptr = %p\n", p, ptr);
	
	p++; 
	ptr++;
	
	printf("p = %p, ptr = %p\n", p, ptr);
	
	return 0;
}

// p = 0x7fff6463e890, ptr = 0x7fff6463e890
// p = 0x7fff6463e894, ptr = 0x7fff6463e8a4


// C program to illustrate sizes of
// pointer of array
#include<stdio.h>

int main()
{
	int arr[] = { 3, 5, 6, 7, 9 };
	int *p = arr;
	int (*ptr)[5] = &arr;
	
	printf("p = %p, ptr = %p\n", p, ptr);
	printf("*p = %d, *ptr = %p\n", *p, *ptr);
	
	printf("sizeof(p) = %lu, sizeof(*p) = %lu\n",
						sizeof(p), sizeof(*p));
	printf("sizeof(ptr) = %lu, sizeof(*ptr) = %lu\n", 
						sizeof(ptr), sizeof(*ptr));
	return 0;
}


// p = 0x7fff55adbff0, ptr = 0x7fff55adbff0
// *p = 3, *ptr = 0x7fff55adbff0
// sizeof(p) = 8, sizeof(*p) = 4
// sizeof(ptr) = 8, sizeof(*ptr) = 20


// C program to print elements of a 2-D array 
// by scripting a pointer to an array 
#include<stdio.h>

int main()
{
int arr[3][4] = { 
					{10, 11, 12, 13}, 
					{20, 21, 22, 23}, 
					{30, 31, 32, 33} 
				};
int (*ptr)[4];
ptr = arr;
printf("%p %p %p\n", ptr, ptr + 1, ptr + 2);
printf("%p %p %p\n", *ptr, *(ptr + 1), *(ptr + 2));
printf("%d %d %d\n", **ptr, *(*(ptr + 1) + 2), *(*(ptr + 2) + 3));
printf("%d %d %d\n", ptr[0][0], ptr[1][2], ptr[2][3]);
return 0;
}

// 0x7ffc9556b790 0x7ffc9556b7a0 0x7ffc9556b7b0
// 0x7ffc9556b790 0x7ffc9556b7a0 0x7ffc9556b7b0
// 10 22 33
// 10 22 33



// Pointers to arrays are particularly useful when dealing with multidimensional arrays or when you need to pass arrays to functions. They provide a way to access and manipulate array elements efficiently.
// Here's a brief example to illustrate the usage of a pointer to an array:
// c
//Copy code


#include <stdio.h>

void printArray(int (*ptr)[5], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[3][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };

    // Pointer to array of 5 integers
    int (*ptr)[5] = arr;

    // Passing pointer to array to a function
    printArray(ptr, 3, 5);

    return 0;
}

# Array of Pointers in C

// C program to demonstrate the use of array of pointers
#include <stdio.h>

int main()
{
	// declaring some temp variables
	int var1 = 10;
	int var2 = 20;
	int var3 = 30;

	// array of pointers to integers
	int* ptr_arr[3] = { &var1, &var2, &var3 };

	// traversing using loop
	for (int i = 0; i < 3; i++) {
		printf("Value of var%d: %d\tAddress: %p\n", i + 1, *ptr_arr[i], ptr_arr[i]);
	}

	return 0;
}


char* arr[5]
	= { "gfg", "geek", "Geek", "Geeks", "GeeksforGeeks" }

// C Program to print Array of strings without array of pointers
#include <stdio.h>
int main()
{
	char str[3][10] = { "Geek", "Geeks", "Geekfor" };

	printf("String array Elements are:\n");

	for (int i = 0; i < 3; i++) {
		printf("%s\n", str[i]);
	}

	return 0;
}


// C program to illustrate the use of array of pointers to
// characters
#include <stdio.h>

int main()
{

	char* arr[3] = { "geek", "Geeks", "Geeksfor" };

	for (int i = 0; i < 3; i++) {
		printf("%s\n", arr[i]);
	}

	return 0;
}


// C program to illustrate the use of array of pointers to
// function
#include <stdio.h>

// some basic arithmetic operations
void add(int a, int b) {
printf("Sum : %d\n", a + b);
}

void subtract(int a, int b) {
	printf("Difference : %d\n", a - b);
}

void multiply(int a, int b) {
	printf("Product : %d\n", a * b);
}

void divide(int a, int b) {
	printf("Quotient : %d", a / b);
}

int main() {

	int x = 50, y = 5;

	// array of pointers to function of return type int
	void (*arr[4])(int, int)
		= { &add, &subtract, &multiply, ÷ };
	for (int i = 0; i < 4; i++) {
		arr[i](x, y);
	}
	return 0;
}
