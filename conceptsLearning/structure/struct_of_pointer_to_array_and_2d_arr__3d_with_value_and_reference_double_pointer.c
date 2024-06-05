#include <stdio.h>
#include <stdlib.h>

// Define a structure representing a student
struct Student {
    char *name;
    int age;
};

// Function to modify student ages using the array of pointers
void modifyAgesByValue(struct Student *students[]) {
    for (int i = 0; i < 3; i++) {
        students[i]->age += 1;

        //or

        // students[0]->age = 1; // Set the age of the first student
        // students[0]->name = "dsds"; // Set the name of the first student
        // students++; // Move to the next student

        //*(students + 0)->age = 1; and students[0]->age = 1; have the same effect of setting the age of the first student in the array to 1.
    }
}

// Function to modify student ages using the pointer to pointer
void modifyAgesByReference(struct Student **students) {
    for (int i = 0; i < 3; i++) {
        (*students[i]).age += 1;

        //or

        //(*students)->age = 1; // Set the age of the first student
        //(*students)++; // Move to the next student

        //students[i]->age += 1;                         // Using the arrow operator
        // (*students[i]).age += 1;                    // Dereferencing the pointer twice
        // (**(students + i)).age += 1;                // Dereferencing the pointer twice
        // students[i][0].age += 1;                    // Using array notation, The usage students[i][0].age is incorrect for array notation in this context. It implies a 2D array 
    }
}

int main() {
    // Define an array of pointers to struct Student
    struct Student *students[3];

    // Allocate memory for each student and initialize
    for (int i = 0; i < 3; i++) {
        students[i] = malloc(sizeof(struct Student));
        students[i]->name = "John"; // Just an example name
        students[i]->age = 20 + i; // Example age
    }

    // Pass by value
    modifyAgesByValue(students);

    // Print student details
    printf("After modification by value:\n");
    for (int i = 0; i < 3; i++) {
        printf("Name: %s, Age: %d\n", students[i]->name, students[i]->age);
    }

    // Pass by reference
    modifyAgesByReference(students);

    /* We canalso call it as
    // Function to modify student ages using the pointer to pointer
void modifyAgesByReference(struct Student ***students) {
    for (int i = 0; i < 3; i++) {
        (*students)[i]->age += 1;
    }
}

    // Pass by reference
        modifyAgesByReference(&students);
     */

    // Print student details
    printf("\nAfter modification by reference:\n");
    for (int i = 0; i < 3; i++) {
        printf("Name: %s, Age: %d\n", students[i]->name, students[i]->age);
    }

    // Free allocated memory
    for (int i = 0; i < 3; i++) {
        free(students[i]);
    }

    return 0;
}



//===========================

//below code for the 2d array of same 

#include <stdio.h>
#include <stdlib.h>

// Define the structure
struct Student {
    int id;
    char name[50];
};

// Function to print the 2D array of structures (passed by value)
void printArrayByValue(struct Student arr[][3], int rows, int cols) {
    printf("Array passed by value:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("ID: %d, Name: %s\n", arr[i][j].id, arr[i][j].name);
        }
    }
}

// Function to print the 2D array of structures (passed by reference)
void printArrayByReference(struct Student **arr, int rows, int cols) {
    printf("Array passed by reference:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("ID: %d, Name: %s\n", arr[i][j].id, arr[i][j].name);
        }
    }
}

int main() {
    int rows = 2;
    int cols = 3;

    // Define a 2D array of structures
    struct Student arr[][3] = { {{1, "John"}, {2, "Alice"}, {3, "Bob"}},
                                {{4, "Emily"}, {5, "David"}, {6, "Emma"}} };

    // Call the function to print the array by value
    printArrayByValue(arr, rows, cols);

    // Call the function to print the array by reference
    struct Student **ptr = malloc(rows * sizeof(struct Student *));
    for (int i = 0; i < rows; i++) {
        ptr[i] = arr[i];
    }
    printArrayByReference(ptr, rows, cols);

    // Free dynamically allocated memory
    free(ptr);

    return 0;
}




//To create a 3D array in C, you can use a similar approach as you did for the 2D array, but with an additional loop. Here's how you can modify the code to create and print a 3D array:
// c
//Copy code


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 2, y = 3, z = 4, i, j, k, count;

    int*** arr = (int***)malloc(x * sizeof(int**));
    for (i = 0; i < x; i++)
    {
        arr[i] = (int**)malloc(y * sizeof(int*));
        for (j = 0; j < y; j++)
        {
            arr[i][j] = (int*)malloc(z * sizeof(int));
        }
    }

    count = 0;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            for (k = 0; k < z; k++)
            {
                arr[i][j][k] = ++count;
            }
        }
    }

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            for (k = 0; k < z; k++)
            {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    /* Code for further processing and free the
       dynamically allocated memory */

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);

    return 0;
}

//This code creates a 3D array with dimensions x, y, and z, and initializes each element with consecutive numbers. Finally, it prints the elements of the 3D array. Make sure to free the dynamically allocated memory after use to avoid memory leaks.




//Yes, you can create a 3D array using a single pointer to pointer (int **arr) in C, but it's a bit trickier compared to using a triple pointer (int ***arr). You can simulate a 3D array using a 1D array with appropriate indexing. Here's how you can do it:

// c
//Copy code


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 2, y = 3, z = 4, i, j, k, count;

    // Allocate memory for a 1D array to simulate a 3D array
    int *arr = (int *)malloc(x * y * z * sizeof(int));

    count = 0;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            for (k = 0; k < z; k++)
            {
                // Calculate the index for 1D array
                int index = (i * y * z) + (j * z) + k;
                arr[index] = ++count;
            }
        }
    }

    // Print the elements of the 3D array
    count = 0;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            for (k = 0; k < z; k++)
            {
                // Calculate the index for 1D array
                int index = (i * y * z) + (j * z) + k;
                printf("%d ", arr[index]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
//In this code, we allocate memory for a 1D array (int *arr) with a size equivalent to the total number of elements in the 3D array. We then calculate the appropriate index for accessing each element as if it were a 3D array. Finally, we print the elements and free the allocated memory.



//Yes, you can create a 3D array using a single pointer to pointer (int **ptr), and then within each index of ptr, you can dynamically allocate memory for another pointer to pointer (int **ptr) to create a 2D array. Here's how you can do it:

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 2, y = 3, z = 4, i, j, k, count;

    // Allocate memory for the first dimension (x)
    int **ptr = (int **)malloc(x * sizeof(int *));
    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        return -1;
    }

    // Allocate memory for the remaining dimensions (y and z) within each index of ptr
    for (i = 0; i < x; i++)
    {
        ptr[i] = (int *)malloc(y * sizeof(int *));
        if (ptr[i] == NULL)
        {
            printf("Memory allocation failed!\n");
            return -1;
        }
        for (j = 0; j < y; j++)
        {
            ptr[i][j] = (int *)malloc(z * sizeof(int));
            if (ptr[i][j] == NULL)
            {
                printf("Memory allocation failed!\n");
                return -1;
            }
        }
    }

    // Initialize and print the elements of the 3D array
    count = 0;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            for (k = 0; k < z; k++)
            {
                ptr[i][j][k] = ++count;
                printf("%d ", ptr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Free the dynamically allocated memory
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            free(ptr[i][j]);
        }
        free(ptr[i]);
    }
    free(ptr);

    return 0;
}


//In this code, we first allocate memory for the first dimension (x) of the 3D array (ptr). Then, within each index of ptr, we allocate memory for the remaining dimensions (y and z) to create a 2D array. Finally, we initialize and print the elements, and free the dynamically allocated memory.↳




// Creating a 3D array in C involves using pointers to pointers to pointers (***) to represent the array in memory. You can then pass this array as a reference to a function and iterate over it. Here's how you can do it:
// c
// Copy code
#include <stdio.h>
#include <stdlib.h>

// Function to iterate over a 3D array
void iterate3DArray(int ***array, int size1, int size2, int size3) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            for (int k = 0; k < size3; k++) {
                printf("%d ", array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    // Define dimensions of the 3D array
    int size1 = 2;
    int size2 = 3;
    int size3 = 4;

    // Dynamically allocate memory for the 3D array
    int ***array = (int ***)malloc(size1 * sizeof(int **));
    for (int i = 0; i < size1; i++) {
        array[i] = (int **)malloc(size2 * sizeof(int *));
        for (int j = 0; j < size2; j++) {
            array[i][j] = (int *)malloc(size3 * sizeof(int));
        }
    }

    // Initialize the 3D array with some values
    int count = 1;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            for (int k = 0; k < size3; k++) {
                array[i][j][k] = count++;
            }
        }
    }

    // Pass the 3D array as a reference to the function and iterate over it
    iterate3DArray(array, size1, size2, size3);

    // Free dynamically allocated memory
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);

    return 0;
}
// In this code:
// We define the dimensions of the 3D array (size1, size2, size3).
// We dynamically allocate memory for the 3D array using nested loops.
// We initialize the array with some values for demonstration purposes.
// We pass the array as a reference to the iterate3DArray function, which iterates over it and prints its elements.
// Finally, we free the dynamically allocated memory to avoid memory leaks.



// If you want to keep the parameter as int **ptr, you can still achieve passing a 3D array, but it might require some extra work to simulate the 3D array using pointer arithmetic. Here's how you can do it:
// c
// Copy code
#include <stdio.h>
#include <stdlib.h>

void print3DArray(int **ptr, int rows, int cols, int depth) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < depth; k++) {
                printf("%d ", *((*((ptr + i) + j)) + k));
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    int rows = 2;
    int cols = 2;
    int depth = 2;

    // Allocate memory for a simulated 3D array
    int ***array3D = (int ***)malloc(rows * sizeof(int **));
    for (int i = 0; i < rows; i++) {
        array3D[i] = (int **)malloc(cols * sizeof(int *));
        for (int j = 0; j < cols; j++) {
            array3D[i][j] = (int *)malloc(depth * sizeof(int));
        }
    }

    // Initialize the simulated 3D array
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < depth; k++) {
                array3D[i][j][k] = count++;
            }
        }
    }

    // Convert the simulated 3D array to a 2D array of pointers
    int **ptr = (int **)malloc(rows * cols * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ptr[i * cols + j] = array3D[i][j];
        }
    }

    // Pass the 2D array of pointers to the function
    print3DArray(ptr, rows, cols, depth);

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            free(array3D[i][j]);
        }
        free(array3D[i]);
    }
    free(array3D);
    free(ptr);

    return 0;
}
// In this example:
// print3DArray function still taint **ptr as a parameter.
// In main, we allocate memory for a simulated 3D array (array3D) and initialize it.
// We then convert the simulated 3D array to a 2D array of pointers (ptr), where each pointer points to a row of the simulated 3D array.
// Finally, we pass this 2D array of pointers to the print3DArray function.
// Remember to free all dynamically allocated memory after its use to prevent memory leaks.



