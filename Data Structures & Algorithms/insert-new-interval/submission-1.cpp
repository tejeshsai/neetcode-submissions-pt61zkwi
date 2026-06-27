class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //sort(intervals.begin(), intervals.end());
        //int lastEnd = intervals[0][1];
        vector<vector<int>> result;
        bool flag = false;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][1]<newInterval[0]){
                //lastEnd = intervals[i][1];
                result.push_back(intervals[i]);
                continue;
            }

            if(newInterval[1]>= intervals[i][0]){
                newInterval[0] = min(intervals[i][0] , newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }

            if(intervals[i][0]>newInterval[1]){
               flag = true;
               result.push_back(newInterval);
               while(i<intervals.size()){
                result.push_back(intervals[i]);
                i++;
               }
               break;
            }
        }
        if(flag == false) result.push_back(newInterval);
        return result;
    }
};
