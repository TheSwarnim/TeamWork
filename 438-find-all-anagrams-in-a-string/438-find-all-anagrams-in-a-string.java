class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int n = s.length(), m = p.length();
        
        int[] count = new int[26];
        for(char c : p.toCharArray()){
            count[c - 'a']++;
        }
        
        List<Integer> res = new LinkedList<>();
        for(int i = 0; i < n; i++){
            count[s.charAt(i) - 'a']--;
            
            if(i >= m){
                count[s.charAt(i-m) - 'a']++;
            }
            
            if(i >= m-1){
                if(allZero(count)){
                    res.add(i - m + 1);
                }
            }
        }
        
        return res;
    }
    
    boolean allZero(int[] count){
        for(int i = 0; i < count.length; i++){
            if(count[i] != 0){
                return false;
            }
        }
        return true;
    }
}