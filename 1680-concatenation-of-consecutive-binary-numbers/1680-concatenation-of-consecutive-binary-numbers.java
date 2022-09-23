class Solution {
    
    long numberOfBits(int n){
        long res = 0, val = 1;
        while(val <= n){
            val <<= 1;
            res++;
        }
        return res;
    }
    
    public int concatenatedBinary(int n) {
        long ans = 0, mod = (long)(1e9) + 7;
        
        for(int i = 1; i <= n; i++){
           long len = numberOfBits(i);
            ans = ((ans << len) % mod + i)%mod;
        }
        return (int)(ans);
    }
} 