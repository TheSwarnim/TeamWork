class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        
        unordered_map<int, vector<int>> row, col;
        for(int i = 0; i < n; i++){
            auto &s = stones[i];
            row[s[0]].push_back(i);
            col[s[1]].push_back(i);
        }
        
        int ans = 0, count = 0;
        for(int i = 0; i < n; i++){
            if(visited[i])
                continue;
            
            queue<int> q; // it will store index
            q.push(i);
            
            while(!q.empty()){
                int idx = q.front(); q.pop();
                
                if(visited[idx])
                    continue;
                
                visited[idx] = true;
                count += 1;
                
                auto &s = stones[idx];
                
                for(auto childIdx : row[s[0]]){
                    if(!visited[childIdx]){
                        q.push(childIdx);
                    }
                }
                
                for(auto childIdx : col[s[1]]){
                    if(!visited[childIdx]){
                        q.push(childIdx);
                    }
                }
            }
            
            ans += count - 1;
            count = 0;
        }
        
        return ans;
    }
};