class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        vector<int> countS(26);
        vector<int> countT(26);
        for(int i=0;i<s.size();i++){
            countS[s[i]-'a']++;
            countT[t[i]-'a']++;
        }

        if(countS==countT){
            return true;
        }
        else{
            return false;
        }
    }
};
