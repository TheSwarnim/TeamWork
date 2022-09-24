class Solution {
    public int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
        int n = nums.length;
        int evensum = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]%2 == 0){
                evensum += nums[i];
            }
        }
        
        int i = 0;
        int[] res = new int[queries.length];
        for(int[] q : queries){
            int val = q[0], index = q[1];
            if(nums[index]%2 == 0){
                if(val%2 == 0){
                    evensum += val;
                } else {
                    evensum -= nums[index];
                }
            } else {
                if(val%2 != 0){
                    evensum += nums[index] + val;
                }
            }
            nums[index] += val;
            res[i++] = evensum;
        }
        
        return res;
    }
}