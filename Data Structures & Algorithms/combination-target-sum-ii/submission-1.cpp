class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;
    void dfs(vector<int>& candidates, int index, int target){
        if(sum == target){
            result.push_back(path);
            return;
        }
        if(sum>target) return;

        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            path.push_back(candidates[i]);
            sum+=candidates[i];
            dfs(candidates, i+1, target);
            path.pop_back();
            sum-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return result;
    }
};
