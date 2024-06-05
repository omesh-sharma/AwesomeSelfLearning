class Solution {
    public int[] twoSum(int[] nums, int target) {

    int target_len = nums.length;

    Map<int, int> storage_map = new Map<int, int>();

    for(int itr=0; itr< target_len; itr++)
    {
        int complement = target - nums[itr];

        if( storage_map.containsvalue(complement) )
        {
            return [storage_map[complement] ,itr]];
        }



        storage_map.put(nums[itr], itr);

    }

    return {-1,-1};


}