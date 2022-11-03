class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        m = defaultdict(int)
        unpaired = ans = 0
        for w in words:
            rev_w = w[::-1]
            if m[rev_w] > 0:
                ans += 4
                m[rev_w] -= 1
                if w[0] == w[1]:
                    unpaired -= 1
            else:
                m[w] += 1
                if w[0] == w[1]:
                    unpaired += 1
        if unpaired > 0:
            ans += 2
        return ans