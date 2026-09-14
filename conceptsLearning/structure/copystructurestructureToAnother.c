// Here the only difference infuncti(data* input) and passed to reference as &source or normal source is witgout & changes made to input won't reflect outside but in case of & it does

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a sub-structure
struct SubStruct {
    int subValue;
};

// Define a main structure containing the sub-structure
struct MainStruct {
    struct SubStruct subStruct;
    int mainValue;
};

int main() {
    // Create instances of the structures
    struct MainStruct struct1, struct2;
    struct1.mainValue = 100;
    struct1.subStruct.subValue = 200;

    // Direct assignment of structures
    struct2 = struct1;

    // Print values of struct2
    printf("Values after direct assignment:\n");
    printf("struct2.mainValue: %d\n", struct2.mainValue); // Output: struct2.mainValue: 100
    printf("struct2.subStruct.subValue: %d\n", struct2.subStruct.subValue); // Output: struct2.subStruct.subValue: 200
    printf("\n");

    // Copying structure without sub-structure by value
    struct2 = struct1;

    // Print values of struct2
    printf("Values after copying without sub-structure by value:\n");
    printf("struct2.mainValue: %d\n", struct2.mainValue); // Output: struct2.mainValue: 100
    printf("struct2.subStruct.subValue: %d\n", struct2.subStruct.subValue); // Output: struct2.subStruct.subValue: 200
    printf("\n");

    // Modifying struct1 for further demonstration
    struct1.mainValue = 500;
    struct1.subStruct.subValue = 700;

    // Copying structure with sub-structure by value
    struct2 = struct1;

    // Print values of struct2
    printf("Values after copying with sub-structure by value:\n");
    printf("struct2.mainValue: %d\n", struct2.mainValue); // Output: struct2.mainValue: 500
    printf("struct2.subStruct.subValue: %d\n", struct2.subStruct.subValue); // Output: struct2.subStruct.subValue: 700

    // Attempt to modify struct2 to see if it affects struct1
    struct2.mainValue = 999;
    struct2.subStruct.subValue = 888;

    // Print values of struct1 to confirm changes do not reflect
    printf("\nValues of struct1 after modifying struct2:\n");
    printf("struct1.mainValue: %d\n", struct1.mainValue); // Output: struct1.mainValue: 500
    printf("struct1.subStruct.subValue: %d\n", struct1.subStruct.subValue); // Output: struct1.subStruct.subValue: 700

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a sub-structure
struct SubStruct {
    int subValue;
};

// Define a main structure containing the sub-structure
struct MainStruct {
    struct SubStruct subStruct;
    int mainValue;
};

// Function to copy a structure to another (without sub-structure)
void copyStructWithoutSub(struct MainStruct source, struct MainStruct *destination) {
    destination->mainValue = source.mainValue;
}

// Function to copy a structure to another (with sub-structure)
void copyStructWithSub(struct MainStruct source, struct MainStruct *destination) {
    *destination = source; // Copy the entire structure from source to destination
}

int main() {
    // Create instances of the structures
    struct MainStruct struct1, struct2;
    struct1.mainValue = 100;
    struct1.subStruct.subValue = 200;

    // Direct assignment of structures
    struct2 = struct1;

    // Print values of struct2
    printf("Values after direct assignment:\n");
    printf("struct2.mainValue: %d\n", struct2.mainValue); // Output: struct2.mainValue: 100
    printf("struct2.subStruct.subValue: %d\n", struct2.subStruct.subValue); // Output: struct2.subStruct.subValue: 200
    printf("\n");

    // Copying structure without sub-structure using function
    copyStructWithoutSub(struct1, &struct2);

    // Print values of struct2
    printf("Values after copying without sub-structure using function:\n");
    printf("struct2.mainValue: %d\n", struct2.mainValue); // Output: struct2.mainValue: 100
    printf("struct2.subStruct.subValue: %d\n", struct2.subStruct.subValue); // Output: struct2.subStruct.subValue: 200
    printf("\n");

    // Modifying struct1 for further demonstration
    struct1.mainValue = 500;
    struct1.subStruct.subValue = 700;

    // Copying structure with sub-structure using function
    copyStructWithSub(struct1, &struct2);

    // Print values of struct2
    printf("Values after copying with sub-structure using function:\n");
    printf("struct2.mainValue: %d\n", struct2.mainValue); // Output: struct2.mainValue: 500
    printf("struct2.subStruct.subValue: %d\n", struct2.subStruct.subValue); // Output: struct2.subStruct.subValue: 700
    printf("\n");

    // Directly copying structure with sub-structure
    struct2 = struct1;

    // Print values of struct2
    printf("Values after direct assignment with sub-structure:\n");
    printf("struct2.mainValue: %d\n", struct2.mainValue); // Output: struct2.mainValue: 500
    printf("struct2.subStruct.subValue: %d\n", struct2.subStruct.subValue); // Output: struct2.subStruct.subValue: 700

    return 0;
}




// /Correct! Changes made to struct1 after copying to struct2 will not reflect in struct2.

// When you copy the structure using:

// c
// Copy code
// *destination = *source;
// it performs a deep copy of the values from struct1 to struct2. This means that struct2 gets its own copy of the data contained in struct1. Therefore, after the copy operation, modifying struct1 will not affect struct2.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a sub-structure
struct SubStruct {
    int subValue;
};

// Define a main structure containing the sub-structure
struct MainStruct {
    struct SubStruct subStruct;
    int mainValue;
};

// Function to copy a structure to another (without sub-structure) using pointers
void copyStructWithoutSub(struct MainStruct *source, struct MainStruct *destination) {
    *destination = *source; // Copy the entire structure from source to destination
}

// Function to copy a structure to another (with sub-structure) using pointers
void copyStructWithSub(struct MainStruct *source, struct MainStruct *destination) {
    *destination = *source; // Copy the entire structure from source to destination
}

int main() {
    // Create instances of the structures as pointers
    struct MainStruct *struct1 = malloc(sizeof(struct MainStruct));
    struct MainStruct *struct2 = malloc(sizeof(struct MainStruct));
    
    // Check if memory allocation was successful
    if (struct1 == NULL || struct2 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Assign values to struct1
    struct1->mainValue = 100;
    struct1->subStruct.subValue = 200;

    // Direct assignment of structures
    *struct2 = *struct1;

    // Print values of struct2
    printf("Values after direct assignment:\n");
    printf("struct2->mainValue: %d\n", struct2->mainValue); // Output: struct2->mainValue: 100
    printf("struct2->subStruct.subValue: %d\n", struct2->subStruct.subValue); // Output: struct2->subStruct.subValue: 200
    printf("\n");

    // Copying structure without sub-structure using function
    copyStructWithoutSub(struct1, struct2);

    // Print values of struct2
    printf("Values after copying without sub-structure using function:\n");
    printf("struct2->mainValue: %d\n", struct2->mainValue); // Output: struct2->mainValue: 100
    printf("struct2->subStruct.subValue: %d\n", struct2->subStruct.subValue); // Output: struct2->subStruct.subValue: 200
    printf("\n");

    // Modifying struct1 for further demonstration
    struct1->mainValue = 500;
    struct1->subStruct.subValue = 700;

    // Copying structure with sub-structure using function
    copyStructWithSub(struct1, struct2);

    // Print values of struct2
    printf("Values after copying with sub-structure using function:\n");
    printf("struct2->mainValue: %d\n", struct2->mainValue); // Output: struct2->mainValue: 500
    printf("struct2->subStruct.subValue: %d\n", struct2->subStruct.subValue); // Output: struct2->subStruct.subValue: 700

    // Free allocated memory
    free(struct1);
    free(struct2);

    return 0;
}


// Special case when member of structure have pointer to heap memory then *dst = *src wont work
No, *(*destination) = *(*source); will not perform a deep copy when dealing with structures that contain pointers. It performs a shallow copy, just like *dest = *src; or memcpy.

Why It’s a Shallow Copy
Pointer Copying: When you use the statement *(*destination) = *(*source);, it copies all the members of the structure from source to destination, including any pointer members. However, it only copies the values of those pointers (the addresses), not the actual data they point to.

Shared Data: After this assignment, both source and destination will point to the same memory locations for any pointer members. If you modify the data pointed to by one structure, it will affect the other structure.

Example Illustration
Here’s a quick example to demonstrate:

c
Copy code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
    int value;
    char *text; // Pointer to a string
};

int main() {
    struct Data *original = malloc(sizeof(struct Data));
    original->value = 42;
    original->text = malloc(20);
    strcpy(original->text, "Hello");

    struct Data *copy = malloc(sizeof(struct Data)); // Allocate memory for copy
    *copy = *original; // Shallow copy (not deep copy)

    // Modify original
    strcpy(original->text, "Goodbye");

    // Print both
    printf("Original: %d, %s\n", original->value, original->text); // Goodbye
    printf("Copy: %d, %s\n", copy->value, copy->text); // Goodbye (not Hello!)

    // Free allocated memory
    free(original->text);
    free(original);
    free(copy->text); // This will be a problem since copy.text points to the same memory
    free(copy); // Don't forget to free the copy itself

    return 0;
}
To Perform a Deep Copy
To ensure a true deep copy, you need to:

Allocate new memory for destination.
Copy each member individually, especially for any pointers.
Example of Deep Copy Function
c
Copy code
void deepCopy(struct Data **source, struct Data **destination) {
    *destination = malloc(sizeof(struct Data));
    if (*destination == NULL) {
        return; // Handle memory allocation failure
    }
    (*destination)->value = (*source)->value;
    
    // Allocate new memory for the text and copy
    (*destination)->text = malloc(strlen((*source)->text) + 1);
    if ((*destination)->text != NULL) {
        strcpy((*destination)->text, (*source)->text);
    }
}
Summary
*(*destination) = *(*source); will not perform a deep copy; it creates a shallow copy.
For deep copying, you must manually allocate memory for each pointer and copy the actual data they point to.



Explanation
What Happens: When you use *(*destination) = *(*source);, you're effectively copying all the members of the structure from source to destination. This includes:

Primitive types (like integers).
Pointers, which are just memory addresses.
Shallow Copy:

If the structure has a pointer (like char *text), both the original and the copy will end up pointing to the same memory location.
Thus, any modification to the data through one structure will reflect in the other, because they share the same address.


The distinction lies in the type of data contained in your structures versus typical cases involving pointers. Let's clarify:

Your Case: Value Types
Structure Composition:

In your code, both MainStruct and SubStruct consist entirely of value types (integers):
c
Copy code
struct SubStruct {
    int subValue; // Value type
};

struct MainStruct {
    struct SubStruct subStruct; // Contains another value type
    int mainValue; // Value type
};
Copying Behavior:

When you use *destination = *source;, it performs a complete copy of the structure's values, including nested structures. Since these are value types, changes to the source after copying do not affect the destination:
This results in independent copies after the assignment.
Typical Case: Pointer Types
Pointers in Structures:

If your structures had pointer members (e.g., char *text;), copying with *destination = *source; would only copy the pointers, leading to both structures pointing to the same memory location. This results in shared data:
Example with pointers:
c
Copy code
struct Data {
    int value;
    char *text; // Pointer
};
Deep Copy Requirement:

In cases where structures contain pointers, you must allocate new memory for the destination and copy the actual data to ensure both structures maintain independent states.
Summary
Your Case:
Using *destination = *source; creates a deep copy effect because you’re dealing with value types. Each structure has its own copy of the data.
Typical Pointer Case:
Requires explicit deep copying techniques to allocate memory and copy data to avoid shared state.
Conclusion
In your case, the structure's composition allows for straightforward copying without worrying about shared pointers, hence you experience the effect of a deep copy. If you switch to using pointers in your structures, you would need to implement deep copy logic explicitly.







// Another :
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mainValue;
    int subValue;
} MainStruct;

int main() {
    MainStruct *struct1 = malloc(sizeof(MainStruct));
    MainStruct *struct2 = malloc(sizeof(MainStruct));

    struct1->mainValue = 100;
    struct1->subValue = 200;

    // Copy struct1 to struct2
    *struct2 = *struct1;

    // Modify struct1
    struct1->mainValue = 500;
    struct1->subValue = 700;

    // Print both structs
    printf("struct1: mainValue = %d, subValue = %d\n", struct1->mainValue, struct1->subValue); // Outputs: 500, 700
    printf("struct2: mainValue = %d, subValue = %d\n", struct2->mainValue, struct2->subValue); // Outputs: 100, 200

    free(struct1);
    free(struct2);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure
struct MyStruct {
    int value;
    char name[20];
};

int main() {
    // Create a pointer to a structure and allocate memory
    struct MyStruct *ptr1 = (struct MyStruct*)malloc(sizeof(struct MyStruct));
    
    // Assign values to the first structure through the pointer
    ptr1->value = 10;
    strcpy(ptr1->name, "Pointer");

    // Create another structure
    struct MyStruct struct2;
    
    // Copy the values from the first structure to the second
    struct2 = *ptr1;

    // Print the values of the second structure
    printf("Value: %d\n", struct2.value);
    printf("Name: %s\n", struct2.name);
    
    // Free the allocated memory
    free(ptr1);

    return 0;
}


// Yes, even if the member name is allocated dynamically using malloc(), it will get copied properly when you use the assignment struct2 = *ptr1;. This is because the assignment operator = copies the entire contents of the structure pointed to by ptr1 to the structure struct2, including the dynamically allocated memory for the name member.
// Here's why it works:
// When you allocate memory for name using malloc(), it creates memory on the heap, and ptr1->name points to this memory.
// When you use the assignment struct2 = *ptr1;, it copies the entire structure pointed to by ptr1 to struct2, including the value of name, which is the address of the dynamically allocated memory.
// After the assignment, struct2.name also points to the same dynamically allocated memory as ptr1->name, so the value of name is effectively copied.
// So, even if name is allocated dynamically, the assignment copies the value of the pointer (which is the address of the dynamically allocated memory), not the actual contents of the dynamically allocated memory. Therefore, both ptr1->name and struct2.name will still point to the same dynamically allocated memory, and the contents of the dynamically allocated memory will remain intact after the assignment.




// To copy just the name from ptr1 to struct2, you can use the strcpy() function to copy the string from one character array to another. Here's how you can modify your code to achieve this:
//c


Copy code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure
struct MyStruct {
    int value;
    char name[20];
};

int main() {
    // Create a pointer to a structure and allocate memory
    struct MyStruct *ptr1 = (struct MyStruct*)malloc(sizeof(struct MyStruct));
    
    // Assign values to the first structure through the pointer
    ptr1->value = 10;
    strcpy(ptr1->name, "Pointer");

    // Create another structure
    struct MyStruct struct2;
    
    // Copy just the name from the first structure to the second
    strcpy(struct2.name, ptr1->name);

    struct2.value = ptr1->value;

    // Print the name copied to the second structure
    printf("Name: %s\n", struct2.name);
    
    // Free the allocated memory
    free(ptr1);

    return 0;
}
//This modification copies only the name from ptr1 to struct2, ignoring the integer value.


// To copy the innerdata member of MyStruct as a deep copy to ptr2, you need to ensure that you allocate memory for ptr2->innerdata and then copy the contents of innerdata from ptr1 to ptr2. Here's how you can do it:
// c
// Copy code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure
struct MyStruct {
    int value;
    char name[20];
    struct MyStruct *innerdata;
};

int main() {
    // Create a pointer to a structure and allocate memory
    struct MyStruct *ptr1 = (struct MyStruct*)malloc(sizeof(struct MyStruct));
    ptr1->innerdata = (struct MyStruct*)malloc(sizeof(struct MyStruct)); // Allocate memory for innerdata
    
    // Assign values to the first structure through the pointer
    ptr1->value = 10;
    strcpy(ptr1->name, "Pointer");
    ptr1->innerdata->value = 20; // Assign value to innerdata
    strcpy(ptr1->innerdata->name, "Inner Pointer");

    // Create another structure
    struct MyStruct *ptr2 = (struct MyStruct*)malloc(sizeof(struct MyStruct));
    ptr2->innerdata = (struct MyStruct*)malloc(sizeof(struct MyStruct)); // Allocate memory for innerdata in ptr2
    
    // Copy the contents of innerdata from ptr1 to ptr2
    *(ptr2->innerdata) = *(ptr1->innerdata); // Deep copy

    // Print the value and name of innerdata copied to ptr2
    printf("Inner Value: %d\n", ptr2->innerdata->value);
    printf("Inner Name: %s\n", ptr2->innerdata->name);
    
    // Free the allocated memory
    free(ptr1->innerdata);
    free(ptr1);
    free(ptr2->innerdata);
    free(ptr2);

    return 0;
}
//This code will copy the innerdata member of ptr1 to ptr2 as a deep copy, meaning a new memory allocation will be made for ptr2->innerdata, and the content will be copied from ptr1->innerdata.↳



// To copy the innerdata member of MyStruct from one instance to another using a function, you can create a function that performs the deep copy operation. Here's how you can implement it:
// c
// Copy code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure
struct MyStruct {
    int value;
    char name[20];
    struct MyStruct *innerdata;
};

// Function to copy innerdata
void copyInnerData(struct MyStruct *src, struct MyStruct *dest) {
    // Allocate memory for innerdata in dest
    dest->innerdata = (struct MyStruct*)malloc(sizeof(struct MyStruct));
    // Copy the contents of innerdata from src to dest
    *(dest->innerdata) = *(src->innerdata); // Deep copy
}

int main() {
    // Create a pointer to a structure and allocate memory
    struct MyStruct *ptr1 = (struct MyStruct*)malloc(sizeof(struct MyStruct));
    ptr1->innerdata = (struct MyStruct*)malloc(sizeof(struct MyStruct)); // Allocate memory for innerdata
    
    // Assign values to the first structure through the pointer
    ptr1->value = 10;
    strcpy(ptr1->name, "Pointer");
    ptr1->innerdata->value = 20; // Assign value to innerdata
    strcpy(ptr1->innerdata->name, "Inner Pointer");

    // Create another structure
    struct MyStruct *ptr2 = (struct MyStruct*)malloc(sizeof(struct MyStruct));

    // Copy innerdata using the function
    copyInnerData(ptr1, ptr2);

    // Print the value and name of innerdata copied to ptr2
    printf("Inner Value: %d\n", ptr2->innerdata->value);
    printf("Inner Name: %s\n", ptr2->innerdata->name);
    
    // Free the allocated memory
    free(ptr1->innerdata);
    free(ptr1);
    free(ptr2->innerdata);
    free(ptr2);

    return 0;
}
//In this code, the copyInnerData function takes two pointers to MyStruct, src and dest, and performs the deep copy of innerdata from src to dest.




// If you want to copy innerdata by reference, you would essentially have both ptr1 and ptr2 pointing to the same memory location for innerdata. Here's how you can do it:
// c
// Copy code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure
struct MyStruct {
    int value;
    char name[20];
    struct MyStruct *innerdata;
};

// Function to copy innerdata by reference
void copyInnerDataByReference(struct MyStruct *src, struct MyStruct *dest) {
    // Simply assign the innerdata pointer from src to dest
    dest->innerdata = src->innerdata;
}

int main() {
    // Create a pointer to a structure and allocate memory
    struct MyStruct *ptr1 = (struct MyStruct*)malloc(sizeof(struct MyStruct));
    ptr1->innerdata = (struct MyStruct*)malloc(sizeof(struct MyStruct)); // Allocate memory for innerdata
    
    // Assign values to the first structure through the pointer
    ptr1->value = 10;
    strcpy(ptr1->name, "Pointer");
    ptr1->innerdata->value = 20; // Assign value to innerdata
    strcpy(ptr1->innerdata->name, "Inner Pointer");

    // Create another structure
    struct MyStruct *ptr2 = (struct MyStruct*)malloc(sizeof(struct MyStruct));

    // Copy innerdata by reference using the function
    copyInnerDataByReference(ptr1, ptr2);

    // Print the value and name of innerdata pointed to by ptr2
    printf("Inner Value: %d\n", ptr2->innerdata->value);
    printf("Inner Name: %s\n", ptr2->innerdata->name);
    
    // Free the allocated memory
    free(ptr1->innerdata);
    free(ptr1);
    free(ptr2); // Note that ptr2->innerdata points to the same memory as ptr1->innerdata, so only free ptr2 itself

    return 0;
}
//In this code, ptr2->innerdata points to the same memory location as ptr1->innerdata, so any changes made to ptr1->innerdata will be reflected in ptr2->innerdata since they are referencing the same memory location.

