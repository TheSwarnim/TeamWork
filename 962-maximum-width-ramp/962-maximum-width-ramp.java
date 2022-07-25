class Solution {
    public int maxWidthRamp(int[] A) {
        int n = A.length, res = 0;
        List<Integer> s = new ArrayList<>();
        for(int i = 0; i < n; i++){
            if(s.size() == 0 || A[i] < A[s.get(s.size() - 1)]) {
                s.add(i);
            }
            else {
                int left = 0, right = s.size() - 1, mid = 0;
                while(left < right) {
                    mid = left + (right - left)/2;
                    if(A[i] < A[s.get(mid)]) 
                        left = mid+1;
                    else
                        right = mid;
                }
                res = Math.max(res, i - s.get(left));
            }
        }
        return res;
    }
}