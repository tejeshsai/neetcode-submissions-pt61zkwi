class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        vector<int> pref(height.size());
        vector<int> suff(height.size());
        pref[0] = height[0];
        suff[height.size()-1] = height[height.size()-1];

        for(int i = 1; i < height.size(); i++){
            pref[i] = max(pref[i-1], height[i]);
        }
        for(int i = height.size() - 2; i >= 0; i--){
            suff[i] = max(suff[i+1], height[i]);
        }

        int total_water = 0;
        for(int i =0;i<pref.size();i++){
            total_water += min(pref[i],suff[i])-height[i];
        }
        return total_water;

    }
};
