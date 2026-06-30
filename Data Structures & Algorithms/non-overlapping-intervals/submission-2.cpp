class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        //vector<vector<int>> result;
        int lastEnd = intervals[0][1];
        //int lastFirst = intervals[0][0];
        for(int i=1;i<intervals.size();i++){
            if(lastEnd > intervals[i][0]){
                count++;
                if(lastEnd>intervals[i][1]){
                    lastEnd = intervals[i][1];
                }
            }else{
                lastEnd = intervals[i][1];
            }
        }
        return count;
    }
};
