class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sorting the vector in accending order of 2nd elements in vector
        sort(intervals.begin(),intervals.end(),cmp);
        
        //keep the prev as the second element of first vector
        //and check whether it is continuing to prev vector
        //if the first element of present vector is less than prev then increment the count
        //else assign prev to second element of present vector
        
        int cnt=0,prev=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<prev)
                cnt++;
            else
                prev=intervals[i][1];
        }
        return cnt;
    }
};