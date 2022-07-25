class Solution {
    private class ArrayValWithOrigIdx{
        int val;
        int originalIdx;
        
        public ArrayValWithOrigIdx(int val, int originalIdx){
            this.val = val;
            this.originalIdx = originalIdx;
        }
    }
    
    public List<Integer> countSmaller(int[] nums) {
        if(nums == null || nums.length == 0) return new ArrayList<>();
        
        int n = nums.length;
        int[] res = new int[n];
        
        ArrayValWithOrigIdx[] newNums = new ArrayValWithOrigIdx[n];
        for(int i = 0; i < n; i++) newNums[i] = new ArrayValWithOrigIdx(nums[i], i);
        
        mergeSortAndCount(newNums, 0, n-1, res);
        
        List<Integer> ans = new ArrayList<>();
        for(int x : res) ans.add(x);
        return ans;
    }
    
    private void mergeSortAndCount(ArrayValWithOrigIdx[] nums, int start, int end, int[] res){
        if(start >= end) return;
        
        int mid = (start + end)/2;
        
        mergeSortAndCount(nums, start, mid, res);
        mergeSortAndCount(nums, mid+1, end, res);
        
        int leftPos = start;
        int rightPos = mid+1;
        List<ArrayValWithOrigIdx> merged = new ArrayList<>();
        int cntOfRightValLessThanLeftVal = 0;
        
        while(leftPos <= mid && rightPos <= end){
            if(nums[leftPos].val > nums[rightPos].val){
                cntOfRightValLessThanLeftVal++;
                merged.add(nums[rightPos]);
                rightPos++;
            } else {
                res[nums[leftPos].originalIdx] += cntOfRightValLessThanLeftVal;
                
                merged.add(nums[leftPos]);
                leftPos++;
            }
        }
        
        while(leftPos <= mid){
            res[nums[leftPos].originalIdx] += cntOfRightValLessThanLeftVal;
            merged.add(nums[leftPos]);
            leftPos++;
        }
        while(rightPos <= end){
            merged.add(nums[rightPos]);
            rightPos++;
        }
        
        int pos = start;
        for(var m : merged){
            nums[pos] = m;
            pos++;
        }
    }
}