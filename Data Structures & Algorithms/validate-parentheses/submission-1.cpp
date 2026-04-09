class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closeToOpen{
            {')','('},{']','['},{'}','{'}
        };
        stack<char> st;
        for(char ch:s){
            if(closeToOpen.count(ch)){
                if(!st.empty() && st.top()==closeToOpen[ch]){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                st.push(ch);
            }
        }
        return st.empty();
    }
};
