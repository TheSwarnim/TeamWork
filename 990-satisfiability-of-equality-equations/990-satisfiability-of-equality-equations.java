class Solution {
    class Disj {
        int n;
        int[] parents;
        
        Disj(){
            n = 26;
            parents = new int[n];
            init();
        }
        
        private void init(){
            for(int i = 0; i < n; i++){
                parents[i] = i;   
            }
        }
        
        int find(int x){
            if(x != parents[x]){
                parents[x] = find(parents[x]);
            }
            return parents[x];
        }
        
        void union(int x, int y){
            x = find(x);
            y = find(y);
            
            if(x != y){
                parents[x] = y;
            }
        }
    }
    
    public boolean equationsPossible(String[] arr) {
        int n = arr.length;
        Disj d = new Disj();
        
        for(String q : arr){
            boolean equal = q.substring(1, 3).equals("==");
            
            if(!equal) {
                continue;
            }
            
            char a = q.charAt(0);
            char b = q.charAt(3);
            // System.out.println(q + " " + a + " " + b + " " + equal + " " + q.substring(1, 3));
            
            if(equal){
                d.union(a - 'a', b - 'a');
            } else {
                // System.out.println(d.find(a - 'a') + " " + d.find(b - 'a'));
                if(d.find(a - 'a') == d.find(b - 'a')){
                    return false;
                }
            }
        }
        
        for(String q : arr){
            boolean equal = q.substring(1, 3).equals("==");
            
            if(equal) {
                continue;
            }
            
            char a = q.charAt(0);
            char b = q.charAt(3);
            // System.out.println(q + " " + a + " " + b + " " + equal + " " + q.substring(1, 3));
            
            if(equal){
                d.union(a - 'a', b - 'a');
            } else {
                // System.out.println(d.find(a - 'a') + " " + d.find(b - 'a'));
                if(d.find(a - 'a') == d.find(b - 'a')){
                    return false;
                }
            }
        }
        
        return true;
    }
}