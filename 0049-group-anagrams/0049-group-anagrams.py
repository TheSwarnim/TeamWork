class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        keyMap = collections.defaultdict(list)
        for word in strs:
            keyMap[tuple(sorted(word))].append(word)
        return list(keyMap.values())