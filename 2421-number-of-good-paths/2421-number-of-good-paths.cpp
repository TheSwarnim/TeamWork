class Solution {
public:
    struct Disj{
        vector<int> parent;
        
        Disj(int n){
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
        }
        
        int find(int x){
            if(x == parent[x]){
                return x;
            }
            return parent[x] = find(parent[x]);
        }
        
        void join(int x, int y){
            x = find(x);
            y = find(y);
            if(x != y){
                parent[x] = y;
            }
        }
    };
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(), goodPaths = 0;
        vector<vector<int>> adj(n);
        map<int, vector<int>> sameValues;
        
        for(int i = 0; i < n; i++){
            sameValues[vals[i]].push_back(i);
        }
        
        for(auto &e : edges){
            int u = e[0], v = e[1];
            
            if(vals[u] >= vals[v]){
                adj[u].push_back(v);
            } else {
                adj[v].push_back(u);
            }
        }
        
        Disj d(n);
        
        for(auto &[value, allNodes] : sameValues){
            for(int u : allNodes){
                for(int v : adj[u]){
                    d.join(u, v);
                }
            }
            
            unordered_map<int, int> group;
            
            for(int u : allNodes){
                group[d.find(u)]++;
            }
            
            goodPaths += allNodes.size();
            
            for(auto &[_, size] : group){
                goodPaths += (size * (size - 1) / 2);
            }
        }
        
        return goodPaths;
    }
};