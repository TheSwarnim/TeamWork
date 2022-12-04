class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(!isCompBitartite(graph, color, i)){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isCompBitartite(vector<vector<int>>& graph, vector<int> &visited, int node) {
        queue<pair<int, int>> q;
        q.push({node, 0});
        while(!q.empty()){
            auto [rnode, level] = q.front(); q.pop();
            
            if(visited[rnode] != -1){
                if(visited[rnode] != level){
                    return false;
                }
                continue;
            }
            
            visited[rnode] = level;
            for(int nbr : graph[rnode]){
                if(visited[nbr] == -1){
                    q.push({nbr, level+1});
                }
            }
        }
        return true;
    }
};