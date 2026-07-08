class Solution {
public:
    vector<string> result;
    string path;
    void dfs(int n, int& openBracket, int& closedBracket){
        if(closedBracket == n){
            result.push_back(path);
        }

        if(openBracket!=n){
            path+="(";
            openBracket+=1;
            dfs(n, openBracket, closedBracket);
            path.pop_back();
            openBracket-=1;
        }

        if(openBracket>closedBracket){
            path+=")";
            closedBracket+=1;
            dfs(n, openBracket, closedBracket);
            path.pop_back();
            closedBracket-=1;
        }
    }

    vector<string> generateParenthesis(int n) {
        int openBracket = 0;
        int closedBracket = 0;

        dfs(n, openBracket, closedBracket);
        return result;
        
    }
};
