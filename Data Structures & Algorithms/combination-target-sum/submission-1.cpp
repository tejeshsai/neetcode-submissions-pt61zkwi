class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    int sum = 0;
    void dfs(vector<int>& nums, int index, int target){
        if(sum==target){
            result.push_back(path);
        }
        if(sum>target){
            return;
        }

        for(int i=index;i<nums.size();i++){
            path.push_back(nums[i]);
            sum+=nums[i];
            dfs(nums,i,target);
            path.pop_back();
            sum-=nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums, 0, target);
        return result;
    }
};
