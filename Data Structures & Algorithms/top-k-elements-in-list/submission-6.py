class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = defaultdict(int)
        freq = [[] for _ in range(len(nums)+1)]

        for n in nums:
            count[n]+=1
        
        for value,frequency in count.items():
            freq[frequency].append(value)

        res = []
        for i in range(len(freq)-1,-1,-1):
            for value in freq[i]:
                res.append(value)
                if(len(res)==k):
                    return res

        return res

        