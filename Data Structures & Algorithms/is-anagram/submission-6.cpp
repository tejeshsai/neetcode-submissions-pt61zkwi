class Solution {
public:
    bool isAnagram(string s, string t) {
        if(!s.size()==t.size()){
            return false;
        }
        vector<int> countS(26);
        vector<int> countT(26);
        for(char ch:s){
            countS[ch-'a']++;
        }
        for(char ch:t){
            countT[ch-'a']++;
        }

        if(countS==countT){
            return true;
        }
        else{
            return false;
        }
    }
};
