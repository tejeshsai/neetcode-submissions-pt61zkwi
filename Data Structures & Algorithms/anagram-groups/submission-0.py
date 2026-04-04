class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        seen_map = {}
        for i in strs:
            count = [0]*26
            for letter in list(i):
                count[ord(letter)-ord("a")]+=1

            if str(count) in seen_map and seen_map[str(count)]:
                seen_map[str(count)].append(i)
            else:
                seen_map[str(count)] = [i]

        return [x for i,x in seen_map.items()]