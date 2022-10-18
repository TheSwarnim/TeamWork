class Solution:
    def countAndSay(self, n: int) -> str:       
        return "1" if n == 1 else self.computeStr(self.countAndSay(n-1))
    
    def computeStr(self, prevResult : str) -> str:
        cnt, val = 0, "$"
        res = ""
        for c in prevResult:
            if val != c:
                if val != "$":
                    res += str(cnt) + val
                val = c
                cnt = 1
            else:
                cnt += 1
        res += str(cnt) + val
        return res
            
            