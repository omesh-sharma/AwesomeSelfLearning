#include <stdio.h>
#include <stdint.h>

// Define a structure representing a student
struct Student {
    char *name;
    int age;
};

// Function to modify the age of a student
void modifyAge(struct Student *student, int newAge) {
    student->age = newAge;
}

int main() {
    // Hexadecimal value representing the address of a structure
    uintptr_t address = 0x7fff5fbff698; // Example address

    // Convert the hexadecimal value to a pointer
    struct Student *ptr = (struct Student *)address;

    // Check if the pointer is valid
    if (ptr != NULL) {
        // Use the pointer to access the structure and modify its age
        modifyAge(ptr, 25);
        printf("Updated age: %d\n", ptr->age);
    } else {
        printf("Invalid pointer\n");
    }

    return 0;
}
