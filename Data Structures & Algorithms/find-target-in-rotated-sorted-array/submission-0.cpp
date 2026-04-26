class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n-1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(nums[mid]<nums[high]){
                high = mid;
            }else{
                low = mid+1;
            }
        }

        int pivot = low;
        if(target>=nums[pivot] && target<=nums[n-1]){
            low = pivot;
            high = n-1;
        }else{
            low = 0;
            high = pivot-1;
        }
        while(low<=high){
            int mid = low+(high-low)/2;
            if(target == nums[mid]) return mid;
            if(target<nums[mid]){
                high=mid-1;
            }else{
                low = mid+1;
            }
        }
        return -1;
    }
};
