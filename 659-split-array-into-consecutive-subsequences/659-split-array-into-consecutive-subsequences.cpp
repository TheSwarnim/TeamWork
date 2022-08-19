class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // borrowed from lee
        
        map<int, int> end, left;
        // left contains all left elements of nums
        // end contains all elements which end with 'i' having atleast 3 elements in it
        for(int &x : nums) left[x]++;
        
        for(int i : nums){
            if(left[i] == 0) continue;
            left[i]--;
            if(end[i-1] > 0){
                end[i-1]--;
                end[i]++;
            } else if(left[i+1]  > 0 && left[i+2] > 0){
                left[i+1]--;
                left[i+2]--;
                end[i+2]++;
            } else {
                return false;
            }
        }
        
        return true;
    }
};