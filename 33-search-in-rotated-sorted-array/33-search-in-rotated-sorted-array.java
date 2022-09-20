class Solution {
    public int search(int[] nums, int target) {
        int l = 0, h = nums.length - 1;
        while(l < h){
            int m = (h-l)/2 + l;
            if(nums[m] > nums[h]) {
                l = m+1;
            } else {
                h = m;
            }
        }
        
        int idx = l;
        l = 0;
        h = nums.length - 1;
        while(l <= h){
            int m = (h-l)/2 + l;
            int realmid = (m+idx)%nums.length;
            if(nums[realmid] == target){
                return realmid;
            } 
            if(nums[realmid] < target){
                l = m+1;
            } else {
                h = m-1;
            }
        }
        return -1;
    }
}