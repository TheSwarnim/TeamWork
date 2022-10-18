class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1: return "1"
        
        prevAns = self.countAndSay(n-1)
        cnt, val = 0, "$"
        res = ""
        for c in prevAns:
            if val != c:
                if val != "$":
                    res += str(cnt) + val
                val = c
                cnt = 1
            else:
                cnt += 1
        res += str(cnt) + val
        return res
            
            