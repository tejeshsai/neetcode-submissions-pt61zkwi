class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        int h = heights.size();
        for(int i = 0; i<=h; i++){
            while(!st.empty() && (i==h || heights[st.top()]>=heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width = st.empty()?i : i-st.top()-1;
                max_area = max(height*width, max_area);
            }
            st.push(i);
        }

        return max_area;
    }
};
