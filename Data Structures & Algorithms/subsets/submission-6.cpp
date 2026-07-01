class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void dfs(vector<int>& nums, int index){
        result.push_back(path);

        for(int i=index;i<nums.size();i++){
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       dfs(nums, 0); 
       return result;
    }
};
