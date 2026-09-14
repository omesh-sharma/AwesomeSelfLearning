# Find Element

---
C 
-------

```

#include <stdio.h>

int findElementInArry(int arr[], int sz, int kk)
{
    int elem = -1;
    for(int itr=0; itr<sz; itr++)
    {
        if (arr[itr] == kk)
        {
            return itr;
        }
    }
    
    return -1;
}

int findElementInArryUsingPointer(int *arr, int sz, int kk)
{
    int elem = -1;
    for(int itr=0; itr<sz; itr++)
    {
        if (arr[itr] == kk)
        {
            return itr;
        }
    }
    
    return -1;
}

int main() {
	// your code goes here
    int arr[] = {1,2,3,4};
    int n = sizeof(arr); #sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", n);
    
    int *arr2 = arr;
    int n2 = sizeof(arr2);
    printf("%d\n", n2);
    
    int res = findElementInArry(arr, 4, 3);
    printf("%d Here is the result\n" , res);
    
    int res2 = findElementInArryUsingPointer(arr, 4, 3);
    printf("%d Here is the result with pointer\n" , res2);
    
}
``
-------
Java
-------

```
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    static int findElementINArry(int arr[], int sz, int kk)
    {
        
        for (int itr=0; itr<sz; itr++)
        {
            if (arr[itr] == kk)
            {
                return itr;
            }
        }
        
        return -1;
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		
		int arr[] = {4,6,8,9};
		int sz = arr.length;
		int pos = findElementINArry(arr, sz, 9);
		System.out.println("Array Element found at position" + pos);

	}
}

```

-------
Javascript
-------

```

// your code goes here
function findElementInArray(arr, sz, kk) {
    for (let itr = 0; itr < sz; itr++) {
        if (arr[itr] == kk) { // Use === for strict equality comparison
            return itr;
        }
    }
    return -1; // Return -1 if the element is not found
}


let arr = [12,3,4,6,7]
let n = arr.length;

let key = 12;

let pos = findElementInArray(arr, n, key);

console.log("Array found at the position \n" + pos);

```

# Insert operation

-------
C
-------

```

void insertAtXPosition(int arr[], int sz, int kk, int pos)
{
    for(int itr=sz-1; itr>=pos; itr--)
    {
        arr[itr+1] = arr[itr];
        
    }
    
    arr[pos] = kk;
}

int main()
{
    
    int arr[6] = {42,33,5,66,88};
    
    int n = 5;
    
    insertAtXPosition(arr, n , 99, 1);
    
    n++;
    
    for(int itr=0; itr<n; itr++)
    {
        printf("Value is %d \n", arr[itr]);
    }
    
    return 0;
}

```

######################################### C++ #############################################

######################################### java #############################################

######################################### python #############################################

######################################### javascript #############################################