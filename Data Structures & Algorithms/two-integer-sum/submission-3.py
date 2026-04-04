class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for i in range(len(nums)):
            j = target - nums[i]
            if j in seen:
                return [seen[j], i]
            else:
                seen[nums[i]] = i
        return [-1, -1]

        

