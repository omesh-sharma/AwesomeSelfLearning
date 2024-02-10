/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {

    let storage_map = new Map();

    let target_len = nums.length;
    for( let itr =0; itr < target_len; itr++ )
        {
            let compliment = target - nums[itr];

            if(storage_map.has(nums[compliment]))
            {
                return [storage_map.get(compliment), itr];
            }

            storage_map.set(nums[itr], itr);
        }

    return [-1,-1];

}