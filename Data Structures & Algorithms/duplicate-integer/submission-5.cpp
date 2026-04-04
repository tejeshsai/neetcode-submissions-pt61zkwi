class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        for(int& num:nums){
            if(numSet.count(num)==0){
                numSet.insert(num);
            }else{
                return true;
            }
        }
        return false;
    }
};