class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        seen_map = defaultdict(list)
        for i, word in enumerate(strs):
            key = [0]*26
            for i in word:
                key[ord(i) - ord("a")] += 1
            seen_map[tuple(key)].append(word)
        answer = []
        for items in seen_map.items():
            answer.append(items[1])
        return answer


                