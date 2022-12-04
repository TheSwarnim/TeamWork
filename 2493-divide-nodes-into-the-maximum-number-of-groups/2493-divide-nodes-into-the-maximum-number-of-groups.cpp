class Solution {
    vector<vector<int>> graph;
    
    int magnificentSetsWithRoot(int root){
        int n = graph.size();
        vector<int> levels(n, -1);
        
        int cur_level = 0;
        
        queue<int> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int iter = 0; iter < size; iter++){
                int node = q.front();
                q.pop();
                
                if(levels[node] == cur_level)
                    continue;
                
                levels[node] = cur_level;
                
                for(auto child : graph[node]){
                    if(levels[child] == -1){
                        q.push(child);
                    } else {
                        if(levels[child] != cur_level+1
                 && levels[child] != cur_level-1){
                            return -1;
                        }
                    }
                }
            }
            
            cur_level++;
        }
        
        return cur_level;
    }
    
    int magnificentSetsInConnectedComp(vector<int> &comp){        
        int res = -1;
        // try for each root independently
        for(int r : comp){
            int rootRes = magnificentSetsWithRoot(r);
            res = max(res, rootRes);
        }
        
        return res;
    }
    
    void dfs(int node, vector<int> &comp, vector<int> &visited){
        if(visited[node]){
            return;
        }
        
        visited[node] = true;
        comp.push_back(node);
        for(int &ch : graph[node]){
            dfs(ch, comp, visited);
        }
    }
    
    vector<vector<int>> connectedComponents(int n){
        vector<int> visited(n, 0);
        
        vector<vector<int>> res;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                vector<int> comp;
                dfs(i, comp, visited);
                res.push_back(comp);
            }
        }
        
        return res;
    }
    
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for(auto &e : edges){
            e[0]--;
            e[1]--;
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        int res = 0;
        
        auto components = connectedComponents(n);
        
        // find answer for each component independently
        for(auto comp : components){
            int compRes = magnificentSetsInConnectedComp(comp);
        
            if(compRes == -1)
                return -1;
            
            res += compRes;
        }
        
        return res;
    }
};