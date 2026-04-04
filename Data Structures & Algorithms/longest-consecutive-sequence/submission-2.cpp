class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_count=0;
        unordered_set<int> seen(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            if(seen.find(curr-1) == seen.end()){
                int length = 1;
                while(seen.find(curr+length)!=seen.end()){
                    length++;
                }
                max_count = max(length, max_count);   
            }
        }
        return max_count;
    }
};
