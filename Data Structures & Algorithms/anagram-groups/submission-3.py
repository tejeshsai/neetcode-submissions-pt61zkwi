class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        seen = defaultdict()

        for s in strs:
            count = [0]*26
            for ch in s:
                count[ord(ch)-ord('a')]+=1
            if str(count) in seen:
                seen[str(count)].append(s)
            else:
                seen[str(count)] = [s]
        res = []
        for value in seen.values():
            res.append(value)

        return res