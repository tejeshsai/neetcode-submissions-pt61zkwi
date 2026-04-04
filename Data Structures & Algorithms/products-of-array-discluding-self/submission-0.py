class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1]*len(nums)
        prefix = 1
        for i in range(len(nums)-1):
            res[i+1] = prefix*nums[i]
            prefix = prefix * nums[i]
        print(res)
        postfix = nums[-1]
        for i in range(len(nums)-1, 0, -1):
            res[i-1] = postfix*res[i-1]
            postfix = postfix*nums[i-1]
        return (res)