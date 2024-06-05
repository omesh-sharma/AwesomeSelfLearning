class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int sum=0;
        vector<int> res;
        for(auto i=0;i<nums.size();i++)
        {
            for(auto j=1;j<nums.size();j++)
            {
                sum+=nums[i]+nums[j];
                if(sum==target && i!=j)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
                sum=0;
            }
        }
        return res;
    }
};