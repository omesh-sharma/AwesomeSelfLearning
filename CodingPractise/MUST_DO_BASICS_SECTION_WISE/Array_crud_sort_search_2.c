#include <stdio.h>
#include <stdlib.h>

// int n = 10;
// //int *masterArray = (int*)malloc(n * sizeof(int));
// int* ptr;
// ptr = (int*)malloc(n * sizeof(int));

int n = 6;
//int *masterArray = (int*)malloc(n * sizeof(int));
int* ptr;

void createRandomArray(int *arr);

void insertElementAtXPos(int *arr);

void deleteELementAtXPos(int *ptr);

void printArray(int *ptr);

void linearSearch(int* ptr);

void bubbleSort(int* ptr);

void selectionSort(int* ptr);

void binarySearch(int* ptr);

void binarySearch(int* ptr)
{
    int mid, beg, end, is_elm_found;
    is_elm_found = 0;

    beg = 0, end =n;
    mid = 0;
    
    bubbleSort(ptr);

    printArray(ptr);

    int target;
    printf("\nEnter the element to be search from array\n");
    scanf("%d", &target);


    while(beg<end)
    {
        mid = (beg+end)/2;

        if (ptr[mid] == target)
        {
            is_elm_found = 1;
            printf("\nElement found at index %d\n", mid+1);
            break;
        }

        else if (target > ptr[mid])
        {
            beg = mid + 1;
        }
        else if (target < ptr[mid])
        {
            end = mid - 1;
        }
    }

    if (!is_elm_found)
    {
        printf("\nNo such element found from the arrray\n");
    }
}

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[])
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */

        printf("\n\nLOOP STARTS\n\n", j);
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];

            printf("i ======= %d  -------- j ====== %d\n", i, j);
            printArray(arr);

            j = j - 1;

            printf("Now J ====== %d\n", j);
        }
        
        printf("\n\nLOOP ENDSSSSSS\n\n", j);
        
        arr[j + 1] = key;

        printArray(arr);
    }
}


void selectionSort(int* ptr)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if (ptr[i] > ptr[j])
            {
                ptr[i] = ptr[i] + ptr[j];
                ptr[j] = ptr[i] - ptr[j];
                ptr[i] = ptr[i] - ptr[j];
            }
        }
    }

    printArray(ptr);
}


void bubbleSort(int* ptr)
{
    // for binary we need to sort the data first;

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(ptr[j] > ptr[j+1]){
                printf("%d  |||||||  %d \n", ptr[j], ptr[j+1]);
                /*
                Example 
                a = 30 
                b = 10
                a = 30+10 = 40
                b = a -b = 40 - 30 = 10
                a = a - b = 40 - 10 = 30
                */
                ptr[j]=ptr[j]+ptr[j+1];
                ptr[j+1]=ptr[j]-ptr[j+1];
                ptr[j]=ptr[j]-ptr[j+1];
            }
        }
    }

    printArray(ptr);

}

void linearSearch(int* ptr)
{
    printf("\nEnter the lement you wanst to search \n");

    int elem;
    scanf("%d", &elem);

    //printf("%d", elem);

    for(int i=0; i<n; i++)
    {
        if (*(ptr + i) == elem)
        {
            printf("Element found at position %d in the array:\n", i);
            return;
        }
    }
}


void printArray(int *ptr)
{
    printf("\n Printing the latest ARRAY \n");
    
    for(int i=0; i<n; i++)
    {
        printf("%d\n", *(ptr++));
    }
}


void insertElementAtXPos(int *ptr)
{

    printf("\n Startign insertion \n");
    int pos;
    printf("ENTER THE POSITION YOU WANT TO ENTER THE ELEMENT \n");
    scanf("%d",&pos);

    for(int i=n; i>=pos; i--)
    {
        ptr[i+1] = ptr[i];
    }

    int element;
    printf("ENTER THE ELEMENT ");
    scanf("%d",&element);

    ptr[pos] = element;

    printArray(ptr);
}

void deleteELementAtXPos(int * ptr)
{
    printf("\n Enter the position at which you wants to delete the element \n");
    int pos;

    scanf("%d", &pos);

    for(int i=pos; i<n; i++)
    {
        ptr[i] = ptr[i+1];
    }

    n = n-1;
    printArray(ptr);

}


void createRandomArray(int * ptr)
{
    printf("\n Creating random array\n");


    // https://stackoverflow.com/questions/72653003/determine-the-length-of-a-dynamic-array-after-creation-time-in-c
    /*
        p is a pointer, sizeof(p) is not the size of the array that was allocated by malloc(), it is just the size of the pointer itself, which may be 4 or 8 depending on the platform (among other more exotic possibilities).

        The expression sizeof(a) / sizeof(a[0]) only works for arrays, defined as int a[10]; or possibly with a length determined at compile time from the intializer: int a[] = { 0, 2, 4 };.

        There is no portable way to retrieve the size of the block allocated by malloc() from the pointer. You must keep track of the size separately.
    */
    // printf("\nsize of pointer is : %d\n", (sizeof(ptr) / sizeof(*(ptr))));
    // printf("\nsize of pointer is : %d\n", *(&ptr + 1) - ptr);
    // #define my_sizeof(type)                                    \
    // ((char*)(&type + 1) - (char*)(&type))
    // printf("\nsize of pointer is : %d\n", my_sizeof(arr) / my_sizeof(arr[0]));


    if (*ptr && ptr != NULL)
    {
        int itr = 0;

        // Uncommenting below will  print more garbage elemnts more than allocated reason
        /*
        
        Usually malloc allocates memory in chunks exactly divisible by the paragraph size equal to 16 bytes 
        (that is malloc allocates chunks with a fundamental alignment requirement). However you should not rely on this internal behavior of malloc. Otherwise the behavior is undefined.*/

        // while(*ptr != '\0')
        while(itr != 5)
        {

            /*
                Other way to initialize array
                int arr[9] = { 0, [1 ... 7] = 10, 0 };
                means 1-7 elemnts of the array will be 10 only

                Same for char array
                char* arr[9] = { "Hello", [1 ... 7] = "JournalDev", "Hi" };
            */
            
            //ptr[itr] = itr;

            // or we can do scanf , by commenting the above
            scanf("%d", ptr+itr);            

            // also can we set element as
            //*(ptr + itr) = itr;

            //printf("%d\n", itr);

            itr++;

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
            //(*ptr) = elem;
            //ptr++;
            // above case in case *ptr = somevalie , then ptr++
        }
    }

    for(int i = 0; i < n; i++)
    {
        //printf("%d\n",*(ptr+i));    

        //or

        // printf("%d\n", *ptr);
        // ptr++;

        //or 

        printf("%d\n",*(ptr++));    
    }
}

void menu()
{
    /*
    1. Insert
    2. Update
    3. Traverse
    4. Delete
    5. Binary search
    6. Linear search
    */

    printf("\n1. INSERTION\t 2. UPDATION\t 3. TRAVERSING\t 4. DELETION\t 5.EXIT\t 6. RECREATE THE ARRAY \n");
    printf("7. LINEAR SEARCH\t 8. BUBBLE SORT\t 9. BINARY SEARCH\t 10. SELECTION SORT 11. Insertion Sort \n\n");

    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            insertElementAtXPos(ptr);
            break;
        case 4:
            deleteELementAtXPos(ptr);
            break;
        case 7:
            linearSearch(ptr);
            break;
        case 8:
            bubbleSort(ptr);
            break;
        case 9:
            binarySearch(ptr);
            break;
        case 10:
            selectionSort(ptr);
            break;
        case 11:
            insertionSort(ptr);
            break;
        default:
            break;
    }    
}

int main()
{

    ptr = (int*)malloc(n * sizeof(int));

    createRandomArray(ptr);

    menu();
}