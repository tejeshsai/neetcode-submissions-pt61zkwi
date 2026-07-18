class Solution {
public:
    unordered_map<char, vector<char>> phn{
        {'2',{'a','b','c'}},
        {'3',{'d','e','f'}},
        {'4',{'g','h','i'}},
        {'5',{'j','k','l'}},
        {'6',{'m','n','o'}},
        {'7',{'p','q','r','s'}},
        {'8',{'t','u','v'}},
        {'9',{'w','x','y','z'}}
    };

    vector<string> result;
    string path;

    void dfs(string digits, int index){
        if(index == digits.size()){
            result.push_back(path);
            return;
        }

        const vector<char>& choices = phn[digits[index]];
        for(const char choice:choices){
            path+=choice;
            dfs(digits, index+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        dfs(digits,0);
        return result;
    }
};
