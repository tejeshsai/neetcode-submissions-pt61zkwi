class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string str : strs){
            res+=to_string(str.length())+"#"+str;
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> res;
        while(i<s.length()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            size_t length = stoul(s.substr(i,j-i));
            j++;
            res.push_back(s.substr(j,length));
            i=j+length;
        }
        return res;
    }
    
};
