class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> set = new HashSet<>(wordList);
        if(!set.contains(endWord)) return 0;
        
        Queue<String> q = new ArrayDeque<>();
        q.offer(beginWord);
        
        int depth = 0;
        while(!q.isEmpty()){
            depth++;
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                String rem = q.poll();
                
                if(rem.equals(endWord)) return depth;
                
                char[] carr = rem.toCharArray();
                for(int j = 0; j < carr.length; j++){
                    for(char c = 'a'; c <= 'z'; c++){
                        carr[j] = c;
                        String newStr = String.valueOf(carr);
                        if(set.contains(newStr)){
                            set.remove(newStr);
                            q.offer(newStr);
                        }
                    }
                    carr[j] = rem.charAt(j);
                }
            }
        }
        
        return 0;
    }
}