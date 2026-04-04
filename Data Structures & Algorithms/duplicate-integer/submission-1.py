class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        unique_list = []
        for x in nums:
            if(x in unique_list):
                return True
            unique_list.append(x)
        return False