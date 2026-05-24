class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq;
        for(char ch:s1){
            freq[ch]++;
        }
        int n = s2.size();
        int l = 0;
        unordered_map<char, int>freq2;
        for(int r=0;r<n;r++){
            if(freq.find(s2[r])!=freq.end()){
                freq2[s2[r]]++;
            }

            if(r-l+1 > s1.length()){
                if(freq.find(s2[l])!=freq.end()){
                    freq2[s2[l]]--;
                }
                if(freq2[s2[l]]==0) freq2.erase(s2[l]);
                l++;
            }

            if(freq==freq2){
                return true; 
            }

        }
        return false;
    }
};
