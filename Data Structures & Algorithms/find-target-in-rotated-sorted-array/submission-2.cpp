class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid]>=nums[low]){ // mid is in LEFT Sorted Partition
                if(nums[low] <= target && target<nums[mid]){ // Target is between lo and mid
                    high = mid-1;
                }else{ // Target is on right of mid
                    low = mid+1;
                }
            }else{ // mid is in RIGHT Sorted partition
                if(nums[mid] < target && target <= nums[high]){// Mid is in RIGHT Sorted Parition and target is between 
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            } 
        }
        return -1;
        
    }
};
