class Solution {
public:
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    
    /*
    color = 0 -> not visited
    color = 1 -> visited in current traversal
    color = 2 -> visited
    */
    
    bool dfs(vvi &graph, vi &color, int node){
        color[node] = 1; // it means visited
        for(int ch : graph[node]){
            if(color[ch] == 0){
                if(dfs(graph, color, ch)) {
                    return true;
                }
            } else if(color[ch] == 1) {
                // visited in current traversal
                return true;
            }
        }
        color[node] = 2;
        return false;
    }
    
    bool hasCycle(vvi &graph, int n){
        vi color(n, 0);
        
        for(int i = 0; i < n; i++){
            if(color[i] == 0 && dfs(graph, color, i)){
                return true;
            }
        }
        
        return false;
    }
    
    void dfs2(vvi &graph, vi &res, int node, vi &visited) {
        visited[node] = 1;
        for(auto it : graph[node]){
            if(!visited[it]){
                dfs2(graph, res, it, visited);
            }
        }
        res.push_back(node);
    }
    
    void topoSort(vvi &graph, vi &res, int n){
        vi visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs2(graph, res, i, visited);
            }
        }
        reverse(begin(res), end(res));
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vvi graph1(k), graph2(k);
        
        for(auto &x : rowConditions){
            graph1[x[0]-1].push_back(x[1]-1);
        }
        for(auto &x : colConditions){
            graph2[x[0]-1].push_back(x[1]-1);
        }
        
        if(hasCycle(graph1, k) || hasCycle(graph2, k)) {
            return {};
        }
        
        vi ans1, ans2;
        topoSort(graph1, ans1, k);
        topoSort(graph2, ans2, k);
        
        vvi res(k, vi(k));
        
        map<int, int> mp;
        for(int j = 0; j < k; j++){
            mp[ans2[j]] = j;
        }
        
        for(int i = 0; i < k; i++){
            res[i][mp[ans1[i]]] = ans1[i] + 1;
        }
        
        return res;
    }
};