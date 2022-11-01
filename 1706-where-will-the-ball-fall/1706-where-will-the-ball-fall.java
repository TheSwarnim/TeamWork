class Solution {
    public int[] findBall(int[][] grid) {
        int n = grid.length, m = grid[0].length, res[] = new int[m];
        for(int ball = 0; ball < m; ball++){
            int j1 = ball, j2;
            for(int i = 0; i < n; i++){
                j2 = j1 + grid[i][j1];
                if(j2 < 0 || j2 >= m || grid[i][j1] != grid[i][j2]) {
                    j1 = -1;
                    break;
                }
                j1 = j2;
            }
            res[ball] = j1;
        }
        return res;
    }
}