class Solution {
public:
    vector<string> path;
    vector<vector<string>> result;

    bool isPalindrome(const string& s){
        int i= 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void dfs(string s, int index){
        if(index == s.size()){
            result.push_back(path);
            return;
        }
        string curr = "";

        for(int i=index;i<s.size();i++){
            curr+=s[i];
            if(isPalindrome(curr)){
                path.push_back(curr);
                dfs(s,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if(s.size()==0) return {};
        dfs(s, 0);
        return result;
    }
};
