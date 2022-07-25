class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size(), res = 0;
        stack<int> s;
        for(int i = 0; i < n; i++)
            if(s.empty() || A[s.top()] > A[i])
                s.push(i);
        for(int i = n-1; i > res; i--)
            while(!s.empty() && A[s.top()] <= A[i])
                res = max(res, i - s.top()), s.pop();
        return res;
    }
};