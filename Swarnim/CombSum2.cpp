class Solution {
public:
    using vi = vector<int>;
    using vvi = vector<vi>;
    /*
    logic: try and check every possible combination in the array
    such that there is no dublicates using backtracking strategy, if find a 
    combination in array equal to target then add it to the ans
    */
    
    vvi ans;
    vi path;
    
    vector<vector<int>> combinationSum2(vector<int>& A, int tar) {
        sort(A.begin(), A.end()); // we sort the array to help us in removing dublicacy in ans
        bt(A, tar, 0); // we start with index=0
        return ans;
    }
    
    void bt(vi &A, int tar, int start){
        if(tar < 0) return; // meaning the total sum of current path exceed the target
        if(tar == 0) { // tar == 0 means we find a valid combination of arr elements
            vi tempPath = path;
            ans.push_back(tempPath);
        } else {
            for(int i = start; i < A.size(); i++){
                if(i > start && A[i] == A[i-1]) continue; // it helps to avoid dublicacy, 
                /* for eg:
                arr = [1,1,2,5]
                in first iteration of arr,
                3 possibilities comes:
                 i) start = 1, path=1
                 ii) start = 2, path=2
                 iii) start = 5, path=5
                 in i) iteration
                    start = 1, path=1,1
                        next iteration is:
                            start=2, path=1,1,2
                    start = 2, path=1,2
                        next iteration is:
                            start=5, path=1,2,5
                    ...
                  so in this way we avoid dublicacy in arr
                */
                path.push_back(A[i]);
                bt(A, tar - A[i], i+1);
                path.pop_back();
            }
        }
    }
};