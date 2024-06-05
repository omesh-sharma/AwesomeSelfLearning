//
// Created by omesh sharma on 08-05-2023.
//
//
// Created by omesh sharma on 04-05-2023.
//
#include "stdio.h"
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {


// ********************************* Solution 1

//
//        vector<int> res_vec;
//
//        int total_len = nums.size();
//
//        if( total_len < 2 || total_len > 100000 || target > 10000000000 || target < -10000000000)
//        {
//            return res_vec;
//        }
//
//
//        int cur_idx = 0;
//
//        for(auto itr: nums)
//        {
//            if( cur_idx < total_len )
//            {
//                int nested_idx = 0;
//
//                for(auto nested_itr: nums)
//                {
//                    if( nested_idx > cur_idx )
//                    {
//                        if( (itr + nested_itr) == target )
//                        {
//                            res_vec.push_back(cur_idx);
//                            res_vec.push_back(nested_idx);
//
//                            break;
//                        }
//                    }
//
//                    nested_idx++;
//                }
//            }
//
//            if( res_vec.size() > 0 )
//                break;
//
//            cur_idx++;
//
//        }
//
//        return res_vec;
//    }


// *************************************** Solution 2 :
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return { map[complement], i };
            }
            map[nums[i]] = i;
        }
        return {-1, -1}; // or return {};
    }

};




int main()
{
    //printf("testing the code");

    Solution caller;

    vector<int> testVec = {3,4,5,6};

    vector<int> res_vec;

    res_vec = caller.twoSum(testVec, 8);

    for( auto itr: res_vec )
    {
        cout<<itr;
    }

    return 0;
}