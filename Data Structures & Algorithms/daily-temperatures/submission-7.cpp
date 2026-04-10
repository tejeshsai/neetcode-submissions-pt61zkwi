class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> monoStack;
        vector<int> result(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            while(!monoStack.empty() && temperatures[i]>temperatures[monoStack.top()]){
                result[monoStack.top()] = i-monoStack.top();
                monoStack.pop();
            }
            monoStack.push(i);
        }
        return result;
    }
};
