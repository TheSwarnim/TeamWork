class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        int cntMaxNonOverlapIntervals = 0, currEndPos = -1e6;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] >= currEndPos){
                currEndPos = intervals[i][1];
                cntMaxNonOverlapIntervals++;
            }
        }
        return intervals.size() - cntMaxNonOverlapIntervals;
    }
};