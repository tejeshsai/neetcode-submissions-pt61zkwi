class Solution {
public:
    string minWindow(string s, string t) {
        int minlen = INT_MAX;
        int l = 0;
        string res = "";
        unordered_map<char , int> freq;
        for(int ch:t){
            freq[ch]++;
        }
        int n = s.size();
        unordered_map<char, int> freq2;
        int formed = 0;
        int required = freq.size();
        for(int r=0;r<n;r++){
            if(freq.find(s[r])!=freq.end()){
                freq2[s[r]]++;
                if(freq2[s[r]] == freq[s[r]]){
                    formed++;
                }
            } 
            // when to update l

            while(formed == required){
                if(r-l+1 < minlen){
                    res = s.substr(l, r-l+1);
                    minlen = r-l+1;
                }

                if(freq.find(s[l])!=freq.end()){
                    freq2[s[l]]--;
                    if(freq2[s[l]]<freq[s[l]]) formed--;
                }
                l++;
            }


        }
        return res;
    }
};
