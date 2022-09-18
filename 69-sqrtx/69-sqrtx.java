class Solution {
    public int mySqrt(int x) {
        long val = 0, res = 0;
        while(val*val <= x){
            res = val;
            val++;            
        }
        return (int)(res);
    }
}