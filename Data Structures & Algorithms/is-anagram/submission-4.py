class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        freqS = {}
        freqT = {}
        for i in range(len(s)):
            freqS[s[i]] = freqS.get(s[i],0) + 1
            freqT[t[i]] = freqT.get(t[i],0) + 1
            
        return freqS == freqT