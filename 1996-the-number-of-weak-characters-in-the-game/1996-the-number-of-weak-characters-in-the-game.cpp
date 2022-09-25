class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [&](vector<int> &p1, vector<int> &p2){
            return p1[0] == p2[0] ? p1[1] > p2[1] : p1[0] < p2[0];
        });
        
        int mtn = INT_MIN;
        int ans= 0;
        for(int i = a.size()-1; i>= 0; i--){
            if(a[i][1] < mtn){
                ans++;
            }
            mtn = max(mtn, a[i][1]);
        }
        
        return ans;
    }
};