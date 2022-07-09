class Solution {
public:
    //Insert the current element and keep checking if the diff between first and last element <limit
    //if greater erase the leftmost element and increment the left pointer
    //keep updating the ans variable at every iteration where ans= max(ans, right-left)
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> m1; // to keep track of max and min element simultaneoulsy
        int l=0,r=0, ans = 1; // left and right pointer
        while(r<nums.size()){
            m1.insert(nums[r]); 
            while(*m1.rbegin() - *m1.begin() > limit){
                //cout<<l<<"*"<<*m1.end() <<"^"<<*m1.begin()<<"&";
                m1.erase(m1.find(nums[l]));
                l++;
            }
            //cout<<l<<r<<" ";
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};