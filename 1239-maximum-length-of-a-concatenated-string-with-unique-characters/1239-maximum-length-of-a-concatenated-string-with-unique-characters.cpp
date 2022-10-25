class Solution {
public:
    int maxLength(vector<string>& arr) {
        return foundMax(arr, 0, unordered_set<char>());
    }
    
    int foundMax(vector<string> &arr, int idx, unordered_set<char> set){
        if(idx == arr.size()){
            return set.size();
        }
        
        int ans = 0;
        
        // try to take first
            // check if word contains all unique values or not
            if(unordered_set<int>(arr[idx].begin(), arr[idx].end()).size() == 
              arr[idx].size()){
                // check if set contains a value that already existed or not
                bool flag = true;
                for(char &c : arr[idx]){
                    if(set.find(c) != set.end()){
                        flag = false;
                    }
                }
                if(flag){
                    for(char &c : arr[idx]){
                        set.insert(c);
                    }
                    ans = max(ans, foundMax(arr, idx+1, set));
                    for(char &c : arr[idx]){
                        set.erase(c);
                    }
                }
            }
        
        // not take this val
        ans = max(ans, foundMax(arr, idx+1, set));
        return ans;
    }
};