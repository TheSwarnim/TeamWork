class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Tuple> pq = new PriorityQueue<>();
        int m = matrix.length;
        for(int j =0; j < m; j++) pq.offer(new Tuple(matrix[0][j], 0, j));
        for(int i = 0; i < k-1; i++){
            Tuple t = pq.poll();
            if(t.x == m-1) continue;
            pq.offer(new Tuple(matrix[t.x+1][t.y], t.x+1, t.y));
        }
        return pq.poll().val;
    }
    
    class Tuple implements Comparable<Tuple>{
        int val;
        int x;
        int y;
        Tuple(int val, int x, int y){
            this.val = val;
            this.x = x;
            this.y = y;
        }
        
        @Override
        public int compareTo(Tuple that){
            return this.val - that.val;
        }
    }
}