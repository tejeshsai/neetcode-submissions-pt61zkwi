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
        string count;
        while(i<n){
            if(s[i]=='#'){
                int c = stoi(count);
                i++;
                result.push_back(s.substr(i,c));
                i+=c;
                count = "";
            }else{
                count+=s[i];
                i++;
            }
            
        }
        return result;
    }
    
};
