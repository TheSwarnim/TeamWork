class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        int[][] dp = new int[n][m];
        
        for(int i = 0; i < n; i++){
            Arrays.fill(dp[i], -1);
        }
        
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                res = Math.max(res, findPath(dp, matrix, i, j));
            }
        }
        
        return res;
    }
    
    private int findPath(int[][] dp, int[][] matrix, int i, int j){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int res = 0;
        
        for(int d = 0; d < 4; d++){
            int x = i + dir[d];
            int y = j + dir[d+1];
            
            if(x < 0 || y < 0 || x >= matrix.length || y >= matrix[0].length || matrix[x][y] <= matrix[i][j]){
                continue;
            }
            
            res = Math.max(res, findPath(dp, matrix, x, y));
        }
        
        res++;
        
        dp[i][j] = res;
        return res;
    }
    
    int[] dir = new int[]{0, 1, 0, -1, 0};
}