class Solution {
public:
    vector<string> path;
    vector<vector<string>> result;
    vector<vector<bool>> dp;
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
            if(dp[index][i] || isPalindrome(curr)){
                dp[index][i] = true;
                path.push_back(curr);
                dfs(s,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if(s.size()==0) return {};
        int n = s.size();
        dp.resize(n, vector<bool>(n, false));
        dfs(s, 0);
        return result;
    }
};
