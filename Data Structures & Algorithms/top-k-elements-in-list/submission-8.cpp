class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<vector<int>> buckets(nums.size()+1);

        for(int n:nums){
            freq[n]++;
        }

        for(const auto& pair:freq){
            buckets[pair.second].push_back(pair.first);
        }
        vector<int> result;
        for(int i=buckets.size()-1;i>0;i--){
            for(int v:buckets[i]){
                result.push_back(v);
                if(result.size()==k) return result;
            }
        }
        return result;

    }
};
