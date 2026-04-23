class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> carPair;
        for(int i=0;i<position.size();i++){
            carPair.push_back({position[i],speed[i]});
        }
        sort(carPair.rbegin(), carPair.rend());
        stack<double> monoStack;
        for(auto& p : carPair){
            double time = (double)(target-p.first)/p.second;
            if(monoStack.empty() || monoStack.top() < time){
                monoStack.push(time);
            }
        }
        return monoStack.size();
    }
};
