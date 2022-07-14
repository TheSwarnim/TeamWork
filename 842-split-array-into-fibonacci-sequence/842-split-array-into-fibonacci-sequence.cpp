class Solution {
public:
    typedef vector<int> vi;
    vector<int> splitIntoFibonacci(string s) {
        vi nums;
        backtrack(s, 0, nums);
        return nums;
    }
    
    bool backtrack(string &s, int start, vi &nums){
        int n = s.size();
        // if start == n & nums have >= 3 elements then return true
        if(start == n && nums.size() >= 3)
            return true;
        
        // if curr char is 0 then we can only take zero otherwise we can take upto 10 digits (32-bit signed interger)
        int maxDigitSize = (s[start] == '0' ? 1 : 10);
        for(int i = 1; i <= maxDigitSize && start+i <= s.size(); i++){
            long long num = stoll(s.substr(start, i));
            if(num > INT_MAX) return false;
            int sz = nums.size();
            if(sz >= 2 && (long long)nums[sz-1]+(long long)nums[sz-2] < num) return false;
            if(sz <= 1 || (long long)nums[sz-1]+(long long)nums[sz-2] == num){
                nums.push_back(num);
                if(backtrack(s, start+i, nums))
                    return true;
                nums.pop_back();
            }
        }
        
        return false;
    }
};