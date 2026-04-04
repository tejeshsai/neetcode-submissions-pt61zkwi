class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seenMap;
        for(int i=0;i<nums.size();i++){
            if(seenMap.count(target - nums[i])){
                return vector<int>{seenMap[target - nums[i]],i};
            }else{
                seenMap[nums[i]] = i;
            }
        }
        return vector<int>{-1,-1};
    }
};
