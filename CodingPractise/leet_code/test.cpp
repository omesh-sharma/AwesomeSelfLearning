//#include <stdio.h>
//#include "stdlib.h"
//#include "string.h"
//
//#include "ctype.h"
//
//// student structure
//struct student {
//    char id[15];
//    char firstname[64];
//    char lastname[64];
//    float points;
//};
//
//// function declaration
//student* getDetail(struct student *);
//
//void displayDetail(struct student *);
//
//char* stringToLower(const char* string) {
//    char *tmp = (char*) malloc(strlen(string) + 1);
//    char *start = tmp;
//    while (*string != 0) {
//        *tmp++ = tolower(*string++);
//    }
//    *tmp = 0;
//    return start;
//}
//
//int main(void) {
//
//    // student structure variable
//    struct student *std;
//
//    // get student detail
//    student *ptr = getDetail(std);
//
//    if(ptr != std)
//    {
//        printf("It's not same");
//    }
//    else
//    {
//        printf("yes it's same");
//    }
//
//    char* data = "omesh sharma";
//
//    char *res = stringToLower(data);
//
//    printf("%s res is \n", data);
//
//    // display student detail
//    //displayDetail(std);
//
//    return 0;
//}
//
//// function definition
//
//
//student* getDetail(struct student *ptr) {
//
//    if(ptr == NULL)
//    {
//        return ptr;
//    }
//    else {
//        return ptr = new student;
//    }
//
////    int i;
////
////    for (i = 0; i < 1; i++) {
////        printf("Enter detail of student #%d\n", (i + 1));
////        printf("Enter ID: ");
////        scanf("%s", ptr->id);
////        printf("Enter first name: ");
////        scanf("%s", ptr->firstname);
////        printf("Enter last name: ");
////        scanf("%s", ptr->lastname);
////        printf("Enter Points: ");
////        scanf("%f", &ptr->points);
////
////        // update pointer to point at next element
////        // of the array std
////        ptr++;
////    }
//
//}
//
//
//
//void displayDetail(struct student *ptr) {
//
//    int i;
//
//    for (i = 0; i < 1; i++) {
//        printf("\nDetail of student #%d\n", (i + 1));
//
//        // display result via ptr variable
//        printf("\nResult via ptr\n");
//        printf("ID: %s\n", ptr->id);
//        printf("First Name: %s\n", ptr->firstname);
//        printf("Last Name: %s\n", ptr->lastname);
//        printf("Points: %f\n", ptr->points);
//
//        // update pointer to point at next element
//        // of the array std
//        ptr++;
//    }
//
//}


// Brm random number logic testing

//#include <stdio.h>
//#include <unistd.h>
//#include "time.h"
//#include <cstdlib>
//
//int pin_random(int* const p_seed)
//{
//    *p_seed = 0x015a4e35L * *p_seed + 1;
//    return (short)((unsigned short)(*p_seed >> 16) & 0x7fff);
//}
//
//int main()
//{
//    int p_pid;
//    int p_id;
//
//    p_id = getpid(); /*process id*/
//    //p_pid = getpid(); /*parent process id*/
//
//    //printf("Process ID: %d\n", p_id);
//    printf("Parent Process ID: %d\n", p_pid);
//
//    while(true) {
//        //srand ( time(NULL) );
//
//        //p_id = getpid(); /*process id*/
//        printf("Inside the while loop  Process ID: %d\n", p_pid);
//        int res = pin_random(&p_id + time()) % 2;
//
//        printf("The res is  %d \n", res);
//
//        res = ( res + 1 ) % 2;
//
//        //printf("On next try the result is   %d \n", res);
//
//
//
//        sleep(1);
//    }
//
//
//
//    return 0;
//}



// GOTO statement sample in the C :
//#include <stdio.h>
//
//int main()
//{
//    // we will print numbers from start to end
//
//    // initialize start and end variables
//    int start = 1, end = 10;
//
//    // initialize variable to keep track of which number is to be printed
//    int curr = start;
//
//    // defining the label
//    print_line :
//
//    // print the current number
//    printf("%d ", curr);
//
//    // check if the current has reached the end
//    // if not, that means some numbers are still to be printed
//    if(curr<end)
//    {
//        // increment current
//        curr++;
//        // use goto to again repeat
//        goto print_line;
//    }
//
//    // if the current has reached the end, the statements inside if will not be executed
//    // the program terminates
//
//
//    return 0;
//}




// LeetCode part

//#include <iostream>
//#include <vector>
//#include <list>
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//
///*
// Approach
// - combined the all array in the single array , array is already sorted.
// - find the length of the array, if the length is odd , then get the center element.
// - If the length of the array is even : then divide the center and next to center number
// */
//
//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//
//
//        int combined_size = nums1.size() + nums2.size();
//
//        if(combined_size >= 2000 || combined_size <= 1 || nums1.size() >= 1000 || nums2.size() >= 1000)
//        {
//            if(nums1.size())
//            {
//                return nums1[0];
//            }
//            else
//            {
//                return nums2[0];
//            }
//
//        }
//
//
//
//
//        int size_stream_1 = nums1.size();
//        int size_stream_2 = nums2.size();
//
//        int sum_count = 0;
//
//        int prev_i, prev_j =-343;
//
//        vector<int> final_arr;
//
//        for(int i=0, j=0; i < size_stream_1 || j < size_stream_2; i++, j++)
//        {
//
//
//            if( i != prev_i && ! (i >= size_stream_1))
//            {
//                //sum_count += nums1[i];
//
//                final_arr.push_back(nums1[i]);
//            }
//            if( j != prev_j  && ! (j >= size_stream_2) )
//            {
//                //sum_count += nums2[j];
//                final_arr.push_back(nums2[j]);
//            }
//
//
//            prev_i = i;
//            prev_j = j;
//
//            if(i > size_stream_1-1)
//            {
//                i--;
//                prev_i = i;
//
//            }
//            if(j > size_stream_2-1)
//            {
//                j--;
//
//                prev_j = j;
//            }
//
//            if ( i == size_stream_1 - 1 && j == size_stream_2 -1)
//            {
//
//                // here we have final vector ready, we can do the final calculation here.
//                vector<int>::iterator ptr;
//
//                sort(final_arr.begin(), final_arr.end());
//
//                //for(ptr = final_arr.begin(); ptr<final_arr.end(); ptr++)
//                //{
//
//                if(final_arr.size() % 2 == 0)
//                {
//                    float res = (float(final_arr[final_arr.size()/2] + final_arr[(final_arr.size()/2) - 1]));
//
//                    return res/2;
//                }
//                else
//                {
//                    int res = final_arr[int(final_arr.size() / 2)];
//                    return res;
//                }
//
//                //return  double(final_arr.size() % 2 ? final_arr[final_arr.size()/2] : double(final_arr[final_arr.size()/2] + final_arr[(final_arr.size()/2)-1])/2);
//                //}
//
//                //double res = sum_count / (size_stream_1 + size_stream_2);
//
//                //return res;
//            }
//
//
//        }
//
//        return double(sum_count);
//
//    }
//};
//
//
//
//void func(int a, int b){};
//int main()
//{
//
//
//    Solution obj;
//
//    vector<int> nums1  = {2}; //{1,2};
//    vector<int> nums2  = {1,3};
//
//    double res =  obj.findMedianSortedArrays(nums1, nums2);
//
//    cout<<"result : "<<res;
//
//
//    return 0;
//
//}//
//// Created by omesh sharma on 11-05-2023.
////


// Brm random number logic testing for the 64 bit compatible with long and long int

/*
 * refrence :
 * https://en.wikipedia.org/wiki/Linear_congruential_generator
 * https://learn.microsoft.com/en-us/cpp/cpp/data-type-ranges?view=msvc-170
 * https://www.rapidtables.com/convert/number/hex-to-decimal.html?x=0x7FFFFFFF
 * https://www.rapidtables.com/convert/number/decimal-to-hex.html
 *
 *
 * http://www.cs.fsu.edu/~lacher/courses/DOCS/c++_threads.html | C++_Threads
https://github.com/CorentinTh | CorentinTh (Corentin THOMASSET)
https://www.google.com/search?q=0x7fff&rlz=1C1CHBD_enIN1010IN1010&oq=0x7fff&aqs=chrome..69i57j0i512l4j0i30l2j0i5i15i30j0i30l2.122j0j9&sourceid=chrome&ie=UTF-8 | 0x7fff - Google Search
https://www.google.com/search?q=0x015a4e35l+&rlz=1C1CHBD_enIN1010IN1010&sxsrf=AB5stBhKuSv1HX75iV80GIM3IrNtoWr6Bw%3A1690456338832&ei=ElHCZMetMrrXseMP0oa9wAg&ved=0ahUKEwjH_tXM4K6AAxW6a2wGHVJDD4gQ4dUDCA8&uact=5&oq=0x015a4e35l+&gs_lp=Egxnd3Mtd2l6LXNlcnAaAhgCIgwweDAxNWE0ZTM1bCAyBBAjGCdI6RRQpgJYtRNwAngBkAEAmAG5AaABgAmqAQMwLji4AQPIAQD4AQHCAgoQABhHGNYEGLADwgIOEAAYigUYsAMYkQIYiwPCAgcQIxiwAhgnwgIFEAAYogTiAwQYACBBiAYBkAYK&sclient=gws-wiz-serp | 0x015a4e35l - Google Search
https://learn.microsoft.com/en-us/dotnet/api/system.int64?view=net-7.0 | Int64 Struct (System) | Microsoft Learn
https://www.rapidtables.com/convert/number/decimal-to-hex.html?x=8 | 8 decimal to hex conversion
https://learn.microsoft.com/en-us/cpp/cpp/data-type-ranges?view=msvc-170 | Data Type Ranges | Microsoft Learn
https://www.rapidtables.com/convert/number/hex-to-decimal.html | Hexadecimal to Decimal Converter
http://www.dynamicdrive.com/dynamicindex12/reflex_dev.htm | Reflex Tester- Developer's View
https://cplusplus.com/reference/random/minstd_rand0/ | cplusplus.com/reference/random/minstd_rand0/
https://stackoverflow.com/questions/19734365/64-bits-seeds-for-random-generators | c++ - 64 bits Seeds for random generators - Stack Overflow
https://www.google.com/search?q=2+*+*+63&rlz=1C1CHBD_enIN1010IN1010&sxsrf=AB5stBgXd5SSvaeEp7RhupLWfYD7LscXlQ%3A1690459552064&ei=oF3CZLS9A5OZseMPhoypkAY&ved=0ahUKEwi0je7I7K6AAxWTTGwGHQZGCmIQ4dUDCA8&uact=5&oq=2+*+*+63&gs_lp=Egxnd3Mtd2l6LXNlcnAaAhgCIggyICogKiA2MzIGEAAYFhgeMgYQABgWGB4yBhAAGBYYHjIGEAAYFhgeMgYQABgWGB4yBhAAGBYYHjIGEAAYFhgeMgYQABgWGB4yBhAAGBYYHjIGEAAYFhgeSIM8UO8YWPY6cAJ4AJABAJgBsgGgAcMJqgEDMC45uAEDyAEA-AEBwgIKECMYigUYsAMYJ8ICERAAGIoFGLEDGIMBGLADGJECwgIOEAAYigUYsAMYkQIYiwPCAgsQABiABBiwAxiLA8ICDhAAGAcYHhiwAxgKGIsDwgIHECMYigUYJ8ICBBAjGCfCAgcQABiKBRhDwgILEAAYgAQYsQMYgwHCAg0QABiKBRixAxiDARhDwgIFEAAYgATCAggQABiABBjLAcICDBAuGBYYHhjHARjRA8ICCRAAGBYYHhjJA8ICCBAAGIoFGJID4gMEGAEgQYgGAZAGCg&sclient=gws-wiz-serp | 2 * * 63 - Google Search
https://stackoverflow.com/questions/70733043/bitwise-operation-xor-mask | c++ - bitwise operation xor mask - Stack Overflow
https://www.google.com/search?q=get+xor+mask&rlz=1C1CHBD_enIN1010IN1010&oq=get+xor+mask+&aqs=chrome..69i57j0i22i30l2j0i390i650l4.2223j0j9&sourceid=chrome&ie=UTF-8 | get xor mask - Google Search
https://ntci.on.ca/compsci/tik/ch8/8_4.htm | 8.4 Home-Made Random Numbers

 *
 */


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <unistd.h>
//
//#include <sys/syscall.h>

//typedef long int int64;
typedef int int32;
typedef unsigned short u_int16;

typedef __int32 int32;                       /* must be 32 bits */
typedef unsigned __int32 u_int32;            /* must be 32 bits */

typedef __int64 int64;
typedef unsigned __int64 u_int64;

#define RAND48_SEED_0   0X330E
#define RAND48_SEED_1   0XABCD
#define RAND48_SEED_2   0X1234
#define RAND48_MULT_0   0XE66D
#define RAND48_MULT_1   0XDEEC
#define RAND48_MULT_2   0X0005


static u_int16 rand48_mult[3] =
        {
                RAND48_MULT_0,
                RAND48_MULT_1,
                RAND48_MULT_2
        };

static u_int16 rand48_add = 0X000B;

static void do_rand48(u_int16 seed_array[3])
{
    u_int32 accu;
    u_int16 temp[2];

    accu =  (u_int32)rand48_mult[0] * (u_int32)seed_array[0]
            + (u_int32)rand48_add;

    /* Lower 16 bits */
    temp[0] = (u_int16) accu;
    accu >>= sizeof(u_int16) * 8;
    accu += (u_int32)rand48_mult[0] * (u_int32)seed_array[1]
            + (u_int32)rand48_mult[1] * (u_int32) seed_array[0];

    /* Middle 16 bits */
    temp[1] = (u_int16) accu;
    accu >>= sizeof(u_int16) * 8;
    accu += rand48_mult[0] * seed_array[2]
            + rand48_mult[1] * seed_array[1]
            + rand48_mult[2] * seed_array[0];

    seed_array[0] = temp[0];
    seed_array[1] = temp[1];
    seed_array[2] = (u_int16)accu;
}


u_int32 pin_lrand48(u_int64* const p_seed)
{
    /*
     *  We let the outside world use a int64 as the seed for convenience, but
     *  internally its an array of 3 shorts, so one of the shorts in the 64 bit
     *  value isn't really ever used. We cast it here to make it look correct
     *  for the internal calls that expect the short array.
     */
    u_int16* p_actual = (u_int16*)p_seed;

    do_rand48(p_actual);
    return ((u_int32)p_actual[2] << 15) + ((u_int32)p_actual[1] >> 1);
}


int pin_random(int* const p_seed)
{

    printf("\n\n %ld \n", *p_seed);
    *p_seed = 0x015a4e35L * *p_seed + 1;
    return (short)((unsigned short)(*p_seed >> 16) & 0x7fff);
    //return (short)((unsigned short)(*p_seed >> 64) & 0x7ffffffff);


}

int pin_random64(int64* const p_seed)
{

    printf("\n\n %ld \n ", *p_seed);
    *p_seed = 0x015a4e35L * *p_seed + 1;
//   return (int64)((unsigned int64)(*p_seed >> 16) & 0x7fff);
    return (int64)((unsigned long int)(*p_seed >> 32) & 0x7fffffff);
}



void* func(void* arg)
{
    // detach the current thread
    // from the calling thread
    pthread_detach(pthread_self());

    printf("Inside the thread\n");

    // exit the current thread
    pthread_exit(NULL);
}

void fun()
{
    pthread_t ptid;

    int64 counter_long = 2147483627; //21474836472;

    int lower = 1, upper = 9, count_ = 1;

    srand(time(0));

    int64 num;

    printf("The random numbers are: ");
    for (int i = 0; i < count_; i++) {
        num = (rand() % (upper - lower + 1)) + lower;

    }

    counter_long = counter_long + (int64)num;

    printf(" %ld  ", counter_long);

    // Creating a new thread
    pthread_create(&ptid, NULL, &func, NULL);
    printf("This line may be printed"
           " before thread terminates\n");

    // The following line terminates
    // the thread manually
    // pthread_cancel(ptid);

    // Compare the two threads created
    if(pthread_equal(ptid, pthread_self()))
        printf("Threads are equal\n");
    else
        printf("Threads are not equal\n");

    // Waiting for the created thread to terminate
    pthread_join(ptid, NULL);

    printf("This line will be printed"
           " after thread ends\n");

    //pthread_exit(NULL);

    int count = 2;

//      ptid = ((getpid() + syscall(SYS_gettid)) % count);

    //int64 random_seed = getpid() + time((time_t *)NULL);  //21474836472; //getpid() + time((time_t *)NULL);
    int64 random_seed = counter_long;

    int64 org_rand = random_seed;
    int64 new_number = random_seed;
    //printf("Random number conversion is %d", new_number);
    //int random_seed = getpid() + syscall(SYS_gettid);
//      ptid = random_seed % count;  //pin_random(&random_seed) % count;
//    ptid = pin_random64(&random_seed) % count;
    ptid =  pin_lrand48((u_int64* const)&random_seed) % count;

//      ptid = pin_random64(&random_seed) % count;

    printf("%d >>>>>>>>>>>> pin_lrand48 returns   %ld  actual seed value was %ld  ", ptid, new_number, org_rand);


//    unsigned short x = 141;
//    unsigned short y = (x >> 4) & 0xf;
    unsigned long int x = 4294967295;
    unsigned long int y = (x >> 32) & 0xffffffff;
    printf("\n xor mask is:     %X \n", y);

    pthread_exit(NULL);


}

// Driver code
int main()
{
    fun();
    return 0;
}

