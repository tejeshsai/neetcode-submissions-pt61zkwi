class Solution {
public:
    int characterReplacement(string s, int k) {
       int l = 0;
       int maxfreq = 0;
       int maxlen = 0;
       int n = s.length();
       unordered_map<char, int> freq;
       for(int r = 0; r < n; r++){
            freq[s[r]]++;
            maxfreq = max(maxfreq, freq[s[r]]);
            if(r-l+1-maxfreq > k){
                freq[s[l]]--;
                l++;
            }
            maxlen = max(maxlen, r-l+1);
       } 
       return maxlen;
    }
};
