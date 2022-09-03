class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        res = []
        
        def rec(n, num):
            if n == 0:
                res.append(num)
            else:
                dig = num%10
                if dig + k < 10:
                    rec(n-1, num*10 + dig + k)
                if dig - k >= 0 and k != 0:
                    rec(n-1, num*10 + dig - k)
        
        for num in range(1, 10):
            rec(n-1, num)
        
        return res
                    