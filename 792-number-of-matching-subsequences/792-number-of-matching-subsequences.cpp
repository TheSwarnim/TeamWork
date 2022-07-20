class Solution {
public:    
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length();
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
        
        /*
        find the idx of all characters of s in a map,
        now we iterate each word in words, while iterating each character
        of a word, we maintain a idx which will keep track of the minimum
        idx of that char in order of increasing order in s
        */
        unordered_map<char, vector<int>> occ;
        for(int i = 0; i < n; i++){
            occ[s[i]].push_back(i);
        }
        
        int ans = 0;
        for(auto &w : words){
            int idx = -1; // idx that will keep track of idx in s of a possible subsequence w in s
            for(int j = 0; j < w.size(); j++){
                char c = w[j];
                
                auto it = upper_bound(begin(occ[c]), end(occ[c]), idx); // find idx of char c in s which have index in s > idx (current index of previous finded i-th character in w)
                if(it == end(occ[c])) break;
                idx = *it; // the next idx will be > *it to complete subsequence in s
                if(j == w.size() - 1) ans++;
            }
        }
        
        return ans;
    }
};