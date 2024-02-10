#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{

    //returnSize = (int*) malloc(numsSize * sizeof (int));

    for(int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                returnSize[0] = i;
                returnSize[1] = j;
                return returnSize;
            }
        }

    }

    return returnSize;
}

int main()
{

    //int* test_arr = (int*) malloc(5* sizeof(int));

    int  test_str[4] = {3,4,5,6};

    //int* ret_data;
    int* ret_data = (int*) malloc(2 * sizeof (int));

    twoSum(test_str, 4, 8, ret_data);

    for(int i=0 ;i < 2; i++)
    {
        printf("%d", ret_data[i]);
    }

    return 0;
}