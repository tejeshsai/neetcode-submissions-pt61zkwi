class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        num = 0
        full_array = range(max(nums)+1)
        print(list(full_array))
        for x in full_array:
            if x not in nums:
                return x
        return x+1