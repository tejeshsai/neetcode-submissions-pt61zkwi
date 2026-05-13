class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string str:strs){
            res+=to_string(str.size())+"#"+str;
        }
        cout << res;
        return res;
        
    }

    vector<string> decode(string s) {
        vector<string> result;
        int n = s.size();
        int i=0;
        while(i<n){
            int j = i;
            while(j<n && s[j]!='#'){
                j++;
            }
            int length = stoi(s.substr(i,j-i));
            result.push_back(s.substr(j+1,length));
            i=j+length+1;
        }
        return result;
    }
    
};
