class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        long sum1 = 0, sum2 = 0, n = arr.size(), res =0;
        auto t = arr;
        sort(t.begin(), t.end());
        for(int i= 0; i < n; i++){
            sum1 += t[i];
            sum2 += arr[i];
            if(sum1 == sum2) res++;
        }
        return res;
    }
};