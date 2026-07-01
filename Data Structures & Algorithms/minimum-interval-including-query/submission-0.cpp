class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end()); //nlogn
        vector<pair<int,int>> sortedQueries;
        for(int i=0;i<queries.size();i++){
            sortedQueries.push_back({queries[i],i});
        }

        sort(sortedQueries.begin(), sortedQueries.end()); //qlogq
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        vector<int> result(queries.size(), -1);

        int j=0;
        for(auto& query:sortedQueries){
            while(j<intervals.size() && intervals[j][0]<=query.first){
                pq.push({intervals[j][1]-intervals[j][0]+1, intervals[j][1]});
                j++;
            }

            while(!pq.empty() && pq.top().second < query.first){
                pq.pop();
            }

            if(!pq.empty()) result[query.second] = pq.top().first;

        }
        return result;

    }
};
