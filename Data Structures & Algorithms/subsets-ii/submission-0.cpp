class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(vector<int>& nums, int index){
        result.push_back(path);

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);

        return result;
    }
};
