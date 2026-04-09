class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closeToOpen{
            {'(',')'},{'[',']'},{'{','}'}
        };
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && closeToOpen[st.top()]==s[i]){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
