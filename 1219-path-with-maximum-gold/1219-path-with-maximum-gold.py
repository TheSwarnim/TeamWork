class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        
        direc = [0, 1, 0, -1, 0]
        
        def dfs(r, c):
            if r < 0 or r >= n or c < 0 or c >= m or grid[r][c] <= 0:
                return 0
            # visited node value is reversed
            grid[r][c] *= -1
            mxTtl = 0
            for i in range(4):
                mxTtl = max(mxTtl, dfs(r+direc[i], c+direc[i+1]))
            grid[r][c] *= -1
            return mxTtl + grid[r][c]
        
        ans = 0
        for r in range(n):
            for c in range(m):
                if grid[r][c] != 0:
                    ans = max(ans, dfs(r, c))
        return ans
            