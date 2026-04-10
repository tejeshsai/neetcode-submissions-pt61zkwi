class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> carFleet(speed.size());
        stack<double> timeSt;
        int result = 0;
        for(int i = 0;i<speed.size();i++){
            carFleet[i]=(pair<int,int>{position[i],speed[i]});
        }
        sort(carFleet.begin(), carFleet.end(),[](const auto& a, const auto& b){
            return a.first > b.first;
        });

        for(int i=0;i<carFleet.size();i++){
            double time = (double)(target - carFleet[i].first) / carFleet[i].second;
            if(timeSt.empty() || time>timeSt.top()){
                timeSt.push(time);
            }
        }

        return timeSt.size();
    }
};
