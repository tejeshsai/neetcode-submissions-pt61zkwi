class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded = ''
        for i,string in enumerate(strs):
            encoded +=string+';'
        return (encoded)
            
    def decode(self, s: str) -> List[str]:
        decoded = s.split(';')[:-1]
        return decoded