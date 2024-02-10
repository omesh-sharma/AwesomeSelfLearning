class Solution:
    def twoSum(self, nums, target):

        spare_list = {}

        for indexing,  itr in enumerate(nums):
            compliment = target - itr

            if compliment in spare_list:
                return [spare_list[compliment], indexing]

            spare_list[itr] = indexing

        return []




test = Solution()

nums = [3,4,5,6]

target = 8

res = test.twoSum(nums, target)

print(res)