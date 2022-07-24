class Solution {
    public long countExcellentPairs(int[] nums, int k) {
        long cnt[] = new long[30], res = 0;
        for(int x : Arrays.stream(nums).distinct().toArray()){
            ++cnt[Integer.bitCount(x)];
        }
        for(int i = 1; i < 30; i++){
            for(int j = 1; j < 30; j++){
                if(i+j >= k)
                    res += cnt[i]*cnt[j];
            }
        }
        return res;
    }
}