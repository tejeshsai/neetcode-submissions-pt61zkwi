class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        r = len(numbers)-1
        while l!=r:
            total = numbers[l]+numbers[r]
            if(total==target):
                return [l+1,r+1]
            else:
                if total > target:
                    r = r-1
                else:
                    l = l+1

        return [-1] 
            