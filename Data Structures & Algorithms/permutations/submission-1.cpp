class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    unordered_set<int> visit;
    void dfs(vector<int>& nums){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visit.find(i)==visit.end()){
                path.push_back(nums[i]);
                visit.insert(i);
                dfs(nums);
                path.pop_back();
                visit.erase(i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return result;
    }
};
