class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> operators{"+","-","*","/"};

        for(string s:tokens){
            if(operators.count(s)){
                int right = (st.top());
                st.pop();
                int left = (st.top());
                st.pop();
                if(s=="+") st.push((left+right));
                else if(s=="-") st.push(left-right);
                else if(s=="*") st.push(left*right);
                else st.push(left/right);
            }else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
