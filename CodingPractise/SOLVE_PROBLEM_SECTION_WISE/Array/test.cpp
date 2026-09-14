#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<int> max_subs;
        int itr = 0;
        if (nums.size() == 1 && k == 1) {
            return nums[0];
        }
        else if (k == nums.size() && count(nums.begin(), nums.end(), nums[0]) == nums.size()) {
            return 0;
        }
       
        while(itr <= nums.size()-k) {
    
            int passes = k-1;
            int sum_val = 0;
            map<int, int> freq;
            while (passes >= 0) {
                if (itr + passes < nums.size()) {
                    if (freq.find(nums[itr + passes]) != freq.end()) {
                        sum_val = 0;
                        //cout<<"value for 4 is set to 0";
                        break;
                    } else {
                        freq[nums[itr + passes]] = 0;
                    }
                    sum_val += nums[itr + passes];
                }
                passes--;
            }
                max_subs.push_back(sum_val);
                itr++;
            }

        long long maxer = INT_MIN;

        for (int i = 0; i < max_subs.size(); i++) {
            if (max_subs[i] > maxer) {
                maxer = max_subs[i];
            }
        }

        return maxer; 
    }
};

int main() {

    Solution caller;

    vector<int> temp_vec = {1,3,2};
    
    cout<<caller.maximumSubarraySum(temp_vec, 3);

    return 0;
}