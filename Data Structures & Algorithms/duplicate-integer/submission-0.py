class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        unique_list = []
        for x in nums:
            if(x not in unique_list):
                unique_list.append(x)
            else:
                return True
        return False