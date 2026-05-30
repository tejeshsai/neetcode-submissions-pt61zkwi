class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq[128] = {0};
        for(char ch:s1){
            freq[ch]++;
        }
        int l = 0;
        int windowSize = s1.length();
        int n = s2.size();
        int freq2[128] = {0};
        for(int r = 0; r<n; r++){
            if(freq[s2[r]]>0){
                freq2[s2[r]]++;
            }
            if(r-l+1 > windowSize){
                if(freq[s2[l]]>0) freq2[s2[l]]--;
                l++;
                cout << r-l+1;
            }

            if(equal(begin(freq), end(freq), begin(freq2))) return true;
        }

        return false;
    }
};
