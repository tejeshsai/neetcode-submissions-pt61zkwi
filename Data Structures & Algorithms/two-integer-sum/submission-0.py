class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            remainder = target - nums[i]
            print(remainder)
            for j in range(i+1,len(nums)):
                print(i, j, nums[j])
                if(remainder == nums[j]):
                    return([i,j])
        
        return []