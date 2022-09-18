class Solution {
    public int mySqrt(int x) {
        if(x == 0) {
            return 0;
        }
        
        int start = 1, end = x;
        while(start < end){
            int mid = (end - start)/2 + start;
            if(mid <= x/mid && (mid+1) > x / (mid + 1)){
                return mid;
            } else if(mid > x / mid){
                end = mid;
            } else {
                start = mid+1;
            }
        }
        return start;
    }
}