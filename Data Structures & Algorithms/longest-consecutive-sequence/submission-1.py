class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if nums == []:
            return 0
        maxLength = 1
        for i in nums:
            length = 1
            j = i
            if i-1 not in nums:
                while(j+1 in nums):
                    length+=1
                    j = j+1
            maxLength = max(length, maxLength)
        return maxLength