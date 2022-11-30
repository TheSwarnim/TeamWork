class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq, freqCnt;
        for(int x : arr){
            freq[x]++;
        }
        for(auto p : freq){
            freqCnt[p.second]++;
            if(freqCnt[p.second] > 1){
                return false;
            }
        }
        return true;
    }
};