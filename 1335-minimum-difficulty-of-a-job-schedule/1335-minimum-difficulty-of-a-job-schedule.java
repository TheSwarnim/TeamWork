class Solution {
    public int minDifficulty(int[] A, int d) {
        final int n = A.length;
        if(n < d) return -1;
        int[][] memo = new int[n][d+1];
        for(int[] row : memo) Arrays.fill(row, -1);
        
        return dfs(d, 0, A, memo);
    }
    
    private int dfs(int d,int len, int[] A, int[][] memo){
        final int n = A.length;
        
        if(d == 0 && len == n) return 0;
        if(d == 0 || len == n) return Integer.MAX_VALUE;
        if(memo[len][d] != -1) return memo[len][d];
        
        int curmax = A[len];
        int min = Integer.MAX_VALUE;
        for(int schedule = len; schedule < n; schedule++){
            curmax = Math.max(curmax, A[schedule]);
            int tmp = dfs(d-1, schedule + 1, A, memo);
            if(tmp != Integer.MAX_VALUE){
                min = Math.min(min, tmp + curmax);
            }
        }
        
        return memo[len][d] = min;
    }
}