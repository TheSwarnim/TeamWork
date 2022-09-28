class Solution {
    public String pushDominoes(String s) {
        /*
        0: idx
        1: pos
            - 1 : left
            - 2 : neutral
            - 3 : right
        2: rank (update only if rank is <= given val)
        */
        int n = s.length();
        
        int[] rank = new int[n];
        int[] pos = new int[n];
        Arrays.fill(pos, 2);
        Arrays.fill(rank, n+2);
        
        Queue<Integer> q = new ArrayDeque<>(); 
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(c != '.'){
                q.offer(i);   
                rank[i] = 0;
                pos[i] = (c == 'L' ? 1 : 3);
            }
        }
        
        while(!q.isEmpty()){
            int size = q.size();
            while(size-- > 0){
                int idx = q.poll();
                
                if(idx > 0 && pos[idx] == 1){
                    if(rank[idx-1] > rank[idx]+1){
                        pos[idx-1] = pos[idx];
                        q.offer(idx-1);
                        rank[idx-1] = rank[idx] + 1;
                    } else if(rank[idx-1] == rank[idx]+1){
                        pos[idx-1] ^= pos[idx];
                    }
                }
                
                if(idx < n-1 && pos[idx] == 3){
                    if(rank[idx+1] > rank[idx]+1){
                        pos[idx+1] = pos[idx];
                        q.offer(idx+1);
                        rank[idx+1] = rank[idx] + 1;
                    } else if(rank[idx+1] == rank[idx]+1){
                        pos[idx+1] ^= pos[idx];
                    }
                }
                
                // System.out.println(Arrays.toString(pos));
                // System.out.println(Arrays.toString(rank));
                // System.out.println(idx);
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++){
            if(pos[i] == 1){
                sb.append('L');
            } else if(pos[i] == 2){
                sb.append('.');
            } else {
                sb.append('R');
            }
        }

        return sb.toString();
    }
}