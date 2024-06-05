// no myquestion is if i modify , it reflect but not free and setting to NULL whey  ?
// ChatGPT
// I see, your question pertains to the behavior of the pointer to the struct player when it's modified within the freStruct function.
// In C, when you pass a pointer to a function, you're passing a copy of the pointer's value. This means that modifying the pointer itself (like assigning it to NULL) inside the function won't affect the original pointer in the calling function unless yo
// However, when you modify the members of the struct that the pointer points to, those changes are reflected outside the function, even if you don't pass a pointer to the pointer.
// Here's why modifying the members of the struct is reflected outside the function:
// When you pass a pointer to a function, you're essentially passing the address of the memory where the struct resides. Any changes made to the contents of that memory are reflected outside the function because you're directly manipulating the data in the memory location pointed to by the pointer.
// In contrast, when you modify the pointer itself (like assigning it to NULL), you're changing the value of the local copy of the pointer within the function. This change is not reflected outside the function because it doesn't affect the original pointer in the calling function.
// So, modifying the members of the struct using the pointer affects the data that the pointer points to, which is why those changes are reflected outside the function. However, modifying the pointer itself (like setting it to NULL) does not affect the original pointer in the calling function because you're working with a copy of the pointer's value.
// User
// but both inside function and outside function struct allocated on heap address is same ?
// ChatGPT
// Yes, that's correct. When you allocate memory dynamically using malloc (or calloc), you're allocating memory from the heap, and you get back a pointer to that allocated memory. This pointer points to the same memory address both inside and outside of the function.
// However, when you pass this pointer to a function in C, you're passing a copy of the pointer's value. This means that the function receive
// When you modify the contents of the memory pointed to by the pointer (e.g., by modifying struct members), those changes are reflected both inside and outside of the function because you're modifying the same memory location.
// On the other hand, when you modify the pointer itself (e.g., by setting it to NULL), you're modifying the local copy of the pointer w


// In C, when you pass a pointer to a function, you are
// When you print the memory address inside and outside the function, you will see the same address because both the original pointer and the copy of the pointer point to the same memory location.
// So, modifications to the memory content itself (e.g., modifying struct members) will be visible outside the function, even though you're working with a copy of the pointer's value. However, modifications to the pointer itself (e.g., setting it to ↳NULL) inside the function will not affect the original pointer in the calling function.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct player {
    char *name;
    int scores[10];
    int length;
} ;


void freStruct(struct player* main_struct)
{
    printf("**************  %p\n", main_struct);
    //main_struct->length = 444;


    // NOTE:   Here free will not reflect outside, it will only free memory in current function scope
    free(main_struct);
    main_struct = NULL;
}

int main()
{

    // *********************************************

    struct player slave_context;
    //slave_context.length = 78;
    void *data_stream = (void *)-1; //(void*) &slave_context; //(void *)-1;
    //data_stream = NULL;
    struct player* new_slave_context = (struct player*)malloc(sizeof(struct player));

    new_slave_context->length = 333;
    printf("**************  %p", new_slave_context);
    freStruct(new_slave_context);

    if(new_slave_context){printf("%d", new_slave_context->length);}

   
    return(0);
}