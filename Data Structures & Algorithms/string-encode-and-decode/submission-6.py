class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for string in strs:
            res+=str(len(string))+"#"+string
        return res
    def decode(self, s: str) -> List[str]:
        i = 0
        result = []
        while(i<len(s)):
            j = i
            while(s[j]!="#"):
                j+=1
            length = int(s[i:j])
            i = j + 1
            result.append(s[i:i+length])
            i+=length
        return result
