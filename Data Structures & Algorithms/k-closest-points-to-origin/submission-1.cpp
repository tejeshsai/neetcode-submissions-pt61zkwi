class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
        pair<int,vector<int>>,
        vector<pair<int, vector<int>>>,
        greater<pair<int,vector<int>>>> pq;
        vector<vector<int>>  result;
        
        if(points.empty()) return result;
        for(auto& point : points){
            pq.push({point[0]*point[0] + point[1]*point[1], point});
        }

        for(int i=0;i<k;i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
