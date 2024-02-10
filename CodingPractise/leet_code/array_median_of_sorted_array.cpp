#include <iostream>
#include <vector>

#include <bits/stdc++.h>

using namespace std;


/*
 Approach
 - combined the all array in the single array , array is already sorted.
 - find the length of the array, if the length is odd , then get the center element.
 - If the length of the array is even : then divide the center and next to center number
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int size_stream_1 = nums1.size();
        int size_stream_2 = nums2.size();

        int sum_count = 0;

        int prev_i, prev_j =-343;

        vector<int> final_arr;

        for(int i=0, j=0; i < size_stream_1 || j < size_stream_2; i++, j++)
        {


            if( i != prev_i && ! (i >= size_stream_1) )
            {
                //sum_count += nums1[i];

                final_arr.push_back(nums1[i]);
            }
            if( j != prev_j  && ! (j >= size_stream_2) )
            {
                //sum_count += nums2[j];
                final_arr.push_back(nums2[j]);
            }

            if ( i == size_stream_1 - 1 && j == size_stream_1 -1)
            {

                // here we have final vector ready, we can do the final calculation here.
                vector<int>::iterator ptr;

                sort(final_arr.begin(), final_arr.end());

                //for(ptr = final_arr.begin(); ptr<final_arr.end(); ptr++)
                //{

                if(final_arr.size()%2 == 0)
                {
                    return float(final_arr[final_arr.size()] + final_arr[final_arr[final_arr.size()] -1] / 2);
                }
                else
                {
                    final_arr[final_arr.size() / 2];
                }

                return  double(final_arr.size() % 2 ? final_arr[final_arr.size()/2] : double(final_arr[final_arr.size()/2] + final_arr[(final_arr.size()/2)-1])/2);
                //}

                //double res = sum_count / (size_stream_1 + size_stream_2);

                //return res;
            }

            prev_i = i;
            prev_j = j;

        }

        return double(sum_count);

    }
};

int main()
{


    Solution obj;

    vector<int> nums1  = {1,3}; //{1,2};
    vector<int> nums2  = {2};

    double res =  obj.findMedianSortedArrays(nums1, nums2);

    cout<<"result : "<<res;


    return 0;

}//
// Created by omesh sharma on 11-05-2023.
//
