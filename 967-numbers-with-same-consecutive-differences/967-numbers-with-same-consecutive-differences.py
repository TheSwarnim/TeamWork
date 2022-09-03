class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        res = []
        
        def dfs(n, num):
            if n == 0:
                res.append(num);
            else:
                dig = num%10
                if dig + k < 10:
                    dfs(n-1, num*10 + dig + k)
                if dig - k >= 0 and k != 0:
                    dfs(n-1, num*10 + dig - k)
        
        for i in range(1, 10):
            dfs(n-1, i)  
        
        return res