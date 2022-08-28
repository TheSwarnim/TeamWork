class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        Map<Integer, PriorityQueue<Integer>> map = new HashMap<>();
        for(int i = 0; i < mat.length; i++){
            for(int j = 0; j < mat[0].length; j++){
                map.
                    computeIfAbsent(i - j, k -> new PriorityQueue<>())
                    .offer(mat[i][j]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mat[i][j] = map.get(i-j).poll();
            }
        }
        return mat;
    }
}