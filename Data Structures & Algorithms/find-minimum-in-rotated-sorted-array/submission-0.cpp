class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int right = nums.size()-1;

        while(low<right){
            int m = low+(right-low)/2;
            if(nums[m] < nums[right]){
                right = m;
            }else{
                low = m+1;
            }
        }
        return nums[low];
    }
};
