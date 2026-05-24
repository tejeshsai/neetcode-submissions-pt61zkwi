class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0;
        unordered_set<char> seen;
        int n = s.size();
        int maxlen = 0;
        for(int r = 0; r<n;r++){
            while(seen.find(s[r])!=seen.end()){
                // already char exists s[r]. Moving l, so we can try to eliminate s[l] ==  s[r] and try next set of chars, which can
                // be maximum length of non-repeating
                seen.erase(s[l]);
                l++;
            }

            
            seen.insert(s[r]);
            maxlen = max(maxlen, (int)seen.size());
            
            
        }
        return maxlen;
    }
};
