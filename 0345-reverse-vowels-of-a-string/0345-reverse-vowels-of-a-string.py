class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = ""
        for c in s:
            if c in "aeiouAEIOU":
                vowels += c
        vowels = vowels[::-1]
        idx = 0
        res = ""
        for c in s:
            if c in "aeiouAEIOU":
                res += vowels[idx]
                idx += 1
            else:
                res += c
        return res