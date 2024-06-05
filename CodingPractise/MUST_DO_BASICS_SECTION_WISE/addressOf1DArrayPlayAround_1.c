//The & operator is used to get the address.
//But in case of array the name of array itself returns its address.
//In array the elements occupy consecutive address,
//therefore incrementing it by 1 each time would give
//the address of next element.

#include<stdio.h>
int main()
{
	int a[100],i,n,*add;
	add = a;
	printf("enter the size: ");
	scanf("%d",&n);
	
    int elem;
	printf("enter the numbers: \n");
	for(i=0;i<n;i++)
	{
		//scanf("%d",&a[i]);
        scanf("%d",&elem);
        *(add + i) = elem;


        /*
            In C, when you have a pointer to an array, you can assign values to the elements of the array using pointer arithmetic. The expression *(add) = elem; is correct if add is a pointer to the first element of an array.
            Let's break down the expression *(add) = elem;:
            *(add) dereferences the pointer add, which means it accesses the value stored at the memory location pointed to by add.
            Since add points to the first element of an array, *(add) refers to the value of the first element in that array.
            elem is assigned to the value at the memory location pointed to by add, effectively setting the value of the first element of the array to elem.
            However, if add is a pointer to a single integer and not an array, then *(add) = elem; would be appropriate for assigning a value to that single integer.
            If add is intended to point to the first element of an array, ensure that it is properly initialized to the address of the array's first element. Otherwise, attempting to dereference it and assign a value to it may result in undefined behavior or a segmentation fault.

            Example
            int a[100],i,n,*add;
	        add = &a[0];
        */
        //*(add) = elem;
        //add++;
	}
	
    add = add + 0;

	for(i=0;i<n;i++)
	{
		// add=a+i;
		// //add = &a[i]; would also return the same thing.
		// printf("The address of element %d is %u.\n",*add, add);	
		
        printf("%d\n",*(add));    
        add++;
        //printf("%d\n",*(add+i));    


		//Notice: As size of int is 4-byte the differnce in address
		//of cosecutive elements is 4.
	}
}

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int *ptr[5];  // Array of int pointers
//     int *add = *ptr;  // Initialize add to point to the first element of ptr

//     // Populate the array
//     for (int i = 0; i < 5; i++) {
//         int elem;
//         printf("Enter value for ptr[%d]: ", i);
//         scanf("%d", &elem);  // Read input from the user
//         *(add + i) = elem;  // Assign value to the memory location pointed to by add
//         add++;  // Move add to point to the next element
//     }

//     // Print the values stored in the array
//     printf("Values stored in the array:\n");
//     for (int i = 0; i < 5; i++) {
//         printf("%d\n", *(ptr[i]));  // Print the value stored at ptr[i]
//     }

//     return 0;
// }
