class Solution {
    class Disj {
        int[] parent;
        
        Disj(int n){
            parent = new int[n];
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }
        
        int find(int x){
            if(x != parent[x]){
                return parent[x] = find(parent[x]);
            }
            return x;
        }
        
        void join(int x, int y){
            x = find(x);
            y = find(y);
            
            if(x != y){
                parent[x] = y;
            }
        }
    }
    
    public int numberOfGoodPaths(int[] vals, int[][] edges) {
        int n = vals.length, ans = 0;
        List<Integer>[] adj = new List[n];
        Map<Integer, List<Integer>> sameVals = new TreeMap<>();
        
        for(int i = 0; i < n ;i++){
            adj[i] = new ArrayList<>();
            sameVals.computeIfAbsent(vals[i], k -> new ArrayList<>()).add(i);
        }
        
        for(int[] e : edges){
            int u = e[0], v = e[1];
            
            if(vals[u] >= vals[v]){
                adj[u].add(v);
            } else {
                adj[v].add(u);
            }
        }
        
        Disj d = new Disj(n);
        
        for(int val : sameVals.keySet()){
            for(int u : sameVals.get(val)){
                for(int v : adj[u]){
                    d.join(u, v);
                }
            }
            
            Map<Integer, Integer> group = new HashMap<>();
            
            for(int u : sameVals.get(val)){
                group.put(d.find(u), group.getOrDefault(d.find(u), 0) + 1);
            }
            
            ans += sameVals.get(val).size();
            
            for(int key : group.keySet()){
                int size = group.get(key);
                ans += size * (size-1) / 2;
            }
        }
        
        return ans;
    }
}