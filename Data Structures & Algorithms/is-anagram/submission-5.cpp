class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>countT(26, 0);
        vector<int>countS(26,0);
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            countS[s[i]-'a']++;
            countT[t[i]-'a']++;
        }

        if(countT==countS) return true;
        return false;
    }
};
