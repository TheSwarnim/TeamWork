class Solution {
public:    
    bool reorderedPowerOf2(int n) {
        auto cnt = findCnt(n);
        
        long long val = 1;
        while(val <= int(1e9)){
            if(canMatch(cnt, val)) {
                return true;
            } 
            val *= 2;
        }
        
        return false;
    }
    
    bool canMatch(vector<int> &cnt, long long pow){
        auto powCnt = findCnt(pow);
        
        for(int i = 0; i < 10; i++){
            if(powCnt[i] != cnt[i]){
                return false;
            }
        }
        
        return true;
    }
    
    vector<int> findCnt(long long n){
        vector<int> cnt(10, 0);
        while(n > 0){
            cnt[n%10]++;
            n/=10;
        }
        return cnt;
    }
};