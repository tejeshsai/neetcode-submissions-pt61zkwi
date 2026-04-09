class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        unordered_set<string> operators{"+","-","*","/"};
        int i = 0;
        int n = tokens.size();
        int result = 0;
        while(i<n){
            if(operators.count(tokens[i])){
                int right = stoi(st.top());
                st.pop();
                int left = stoi(st.top());
                st.pop();
                if(tokens[i] == "+") result=left+right;
                else if(tokens[i] == "-") result=left-right;
                else if(tokens[i] == "*") result=left*right;
                else result=left/right;
                st.push(to_string(result));
                
            }else{
                st.push(tokens[i]);
            }
            i++;
        }
        return stoi(st.top());
    }
};
