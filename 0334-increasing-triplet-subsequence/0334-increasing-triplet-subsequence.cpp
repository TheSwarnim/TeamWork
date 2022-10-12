class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j < n; j++){
        //         for(int k = j+1; k < n; k++){
        //             if(nums[i] < nums[j] && nums[j] < nums[k]){
        //                 return true;
        //             }
        //         }
        //     }
        // }
        
        vector<bool> flags(n);
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         if(nums[i] < nums[j]){
        //             flags[j] = true;
        //         }
        //     }
        // }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         if(flags[i] && nums[i] < nums[j]){
        //             return true;
        //         }
        //     }
        // }
        
         int c1 = INT_MAX, c2 = INT_MAX;
        for (int x : nums) {
            if (x <= c1) {
                c1 = x;           // c1 is min seen so far (it's a candidate for 1st element)
            } else if (x <= c2) { // here when x > c1, i.e. x might be either c2 or c3
                c2 = x;           // x is better than the current c2, store it
            } else {              // here when we have/had c1 < c2 already and x > c2
                return true;      // the increasing subsequence of 3 elements exists
            }
        }
        return false;
    }
};