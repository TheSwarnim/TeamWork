class Solution {
public:    
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length(), m = words.size();
        /*
        1) bruteforce: for each word in words, check if it is a subsequence 
        of s
        
        int ans = 0;
        for(auto &w : words){
            int i = 0, j = 0;
            while(i < n && j < w.length()){
                if(s[i] == w[j]) j++;
                i++;
            }
            if(j == w.length()) ans++;
        }
        return ans;
        */
        
        map<char, vector<int>> firstOcc;
        for(int i = 0; i < n; i++){
            firstOcc[s[i]].push_back(i);
        }
        
        int ans = 0;
        for(auto &w : words){
            int latest = -1;
            for(int j = 0; j < w.size(); j++){
                char c = w[j];
                auto it = upper_bound(firstOcc[c].begin(), firstOcc[c].end(), latest);
                if(it == firstOcc[c].end()) break;
                latest = *it;
                if(j == w.size() - 1) ans++;
            }
        }
        
        return ans;
    }
};