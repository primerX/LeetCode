class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int mid = 0;

        while(low < high){
              // Find the index of middle element
            mid = low + (high - low) / 2;
            // Compare middle element with its neighbours (if neighbours exist)
            if((mid == 0 || nums[mid] > nums[mid-1]) && (mid == nums.size()-1 || nums[mid] > nums[mid+1])){
                return mid;
            }
            // If middle element is not peak and its left neighbor is greater than it
            // then left half must have a peak element
            if(mid >0 && nums[mid-1] > nums[mid]){
                high = mid - 1;
            // If middle element is not peak and its right neighbor is greater than it
            // then right half must have a peak element
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};