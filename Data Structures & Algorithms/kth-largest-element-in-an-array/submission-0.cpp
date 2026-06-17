class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<
        int,
        vector<int>,
        greater<int>> pq;
        if(nums.empty()) return 0;
        for(int num:nums){
            pq.push(num);
            if(pq.size()>k) pq.pop();
        }

        return pq.top();
    }
};
