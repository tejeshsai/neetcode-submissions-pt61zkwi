class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int i = 0;
        int n = temperatures.size();
        stack<int> st;
        vector<int> result(n, 0);
        for(int i=0;i<temperatures.size();i++){
            
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                result[st.top()] = i-st.top();
                st.pop();
            }
            
            st.push(i);
        }
        return result;
    }
};
