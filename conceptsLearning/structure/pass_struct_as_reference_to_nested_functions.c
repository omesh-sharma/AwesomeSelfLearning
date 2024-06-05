// how to pass structure by reffernce to nestd function , example we define  struct in function A , and from a called function B , then function B called C to pass that structure .
// ChatGPT
// To pass a structure by reference through nested functions in C, you can achieve this by passing a pointer to the structure. Here's an example demonstrating this:
// c
// Copy code
#include <stdio.h>
#include <stdlib.h>

// Define the structure representing a student
struct Student {
    char *name;
    int age;
};

// Function C
void printStudent(struct Student *student) {
    printf("Name: %s, Age: %d\n", student->name, student->age);
}

// Function B: Calls function C and passes the student structure
void functionB(struct Student *student) {
    // Call function C and pass the student structure
    printStudent(student);
}

// Function A: Defines th
void functionA() {
    // Allocate memory for the student structure
    struct Student *student = malloc(sizeof(struct Student));
    if (student == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Initialize the student structure
    student->name = "John";
    student->age = 20;

    // Call function
    functionB(student);

    // Free the allocated memory for the student structure
    free(student);
}

int main() {
    // Call function A
    functionA();

    return 0;
}

// In this example:
// We define a structure struct Student representing a student with name and age fields.
// Function C (printStudent) takes a pointer to a struct Student as a parameter and prints its details.
// Function BfunctionB) takes a pointer to a struct Student as a parameter and calls function C with the student structure.
// Function A (functionA) allocates memory for a struct Student, initializes its fields, and calls function B with the student structure.
// In the main function
// This way, th
// User
// so functionB is containt copy of structure or refernece
// ChatGPT
// In C, when you pass a structure pointer to a function, you are passing the address of the structure in memory. This means that the function receives a reference t
// In the provided example, when you call functionB from functionA and pass the student pointer as an argument, functionB receives a reference to the original struct Student object created in functionA. Therefore, any modifications made to the structure within functionB will directly affect the original structure in functionA. This is because both functions are operating on the same memory location where the structure resides.

// User
// ok but if ii want to pass as reference to nested functions
// ChatGPT
// To pass a structure by reference to nested functions in C, you can follow these steps:

// Define the structure.
// Pass a pointer to the structure to each function.
// Here's an example demonstrating this:
// c
// Copy code

#include <stdio.h>
#include <stdlib.h>

// Define the structure representing a student
struct Student {
    char *name;
    int age;
};

// Function C: Prints the details of the student
void printStudent(struct Student *student) {
    printf("Name: %s, Age: %d\n", student->name, student->age);
}

// Function B: Calls function C and passes the student structure by reference
void functionB(struct Student *student) {
    // Call function C and pass the student structure by reference
    printStudent(student);
}

// Function A: Defines the student structure and calls function B
void functionA() {
    // Allocate memory for the student structure
    struct Student *student = malloc(sizeof(struct Student));
    if (student == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Initialize the student structure
    student->name = "John";
    student->age = 20;

    // Call function B and pass the student structure by reference
    functionB(student);

    // Free the allocated memory for the student structure
    free(student);
}

int main() {
    // Call function A
    functionA();

    return 0;
}


// In this example:

// We define a structure struct Student representing a student with name and age fields.
// Each function receives a pointer to the structure as a parameter, allowing them to access and modify the same instance of the struc
// functionA allocates memory for a struct Student, initializes its fields, and calls functionB with the student structure by reference.
// functionB calls printStudent and passes the student structure by reference.
// printStudent prints the details of the student using the passed structure reference.
// This way, all functio
// User
// But i want to pass as **
// ChatGPT
// If you want to pass a pointer to a pointer to a structure (struct Student **) to nested functions, you can do so by following these steps:
// Define the structure.
// Allocate memory for the structure and initialize its fields in the outer function.
// Pass a pointer to the pointer to the structure to each function.
// Here's an example demonstrating this:

// c
// Copy code


#include <stdio.h>
#include <stdlib.h>

// Define the structure representing a student
struct Student {
    char *name;
    int age;
};

// Function
void printStudent(struct Student **studentPtr) {
    printf("Name: %s, Age: %d\n", (*studentPtr)->name, (*studentPtr)->age);
}

// Function B: Calls function C and passes the student structure by reference
void functionB(struct Student **studentPtr) {
    // Call function
    printStudent(studentPtr);
}

// Function A: Defin
void functionA() {
    // Allocate memory for the student structure
    struct Student *student = malloc(sizeof(struct Student));
    if (student == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Initialize the student structure
    student->name = "John";
    student->age = 20;

    // Call function B and pass a pointer to the pointer to the student structure
    functionB(&student);

    // Free the allocated memory for the student structure
    free(student);
}

int main() {
    // Call function A
    functionA();

    return 0;
}


// In this example:

// We define a structure struct Student representing a student with name and age fields.
// The outer function functionA allocates memory for a struct Student, initializes its fields, and calls functionB with a pointer to a pointer to the student structure.
// functionB calls printStudent and passes the pointer to the pointer to the student structure.
// printStudent dereferences the pointer to the pointer to access the student structure and prints its details.
// This way, you can pass a pointer to a pointer to a structure to nested functions in C.