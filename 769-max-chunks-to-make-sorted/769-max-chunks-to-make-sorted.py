class Solution:
    def maxChunksToSorted(self, A: List[int]) -> int:
        res, s1, s2 = 0, 0, 0
        for a, b in zip(A, sorted(A)):
            s1 += a
            s2 += b
            if s1 == s2:
                res += 1
        return res