class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seenMap = defaultdict();
        for i,num in enumerate(nums):
            if(target-num in seenMap):
                return [seenMap[target-num],i]
            else:
                seenMap[num] = i
                
        return []