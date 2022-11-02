class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string, int>> q;
        unordered_set<string> visited, bankSet(bank.begin(), bank.end());
        q.push({start, 0});
        while(!q.empty()){
            auto [str, cost] = q.front(); q.pop();
            
            if(visited.find(str) != visited.end()){
                continue;
            }
            
            visited.insert(str);
            
            if(str == end){
                return cost;
            }
    
            for(int i = 0; i < str.size(); i++){
                char c = str[i];
                
                for(char ch : geneString){
                    
                    if(ch != c){
                    
                        str[i] = ch;
                        if(bankSet.find(str) != bankSet.end() && visited.find(str) == visited.end()){
                            q.push({str, cost+1});
                        }
                        
                    }
                }
                
                str[i] = c;
            }
        }
        
        return -1;
    }
    
    vector<char> geneString = {'A', 'C', 'G', 'T'};
};