class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int mid = 0;

        while(low < high){
        	mid = low + (high - low) / 2;
        	if(( mid == 0 || nums[mid] > nums[mid-1] )  && nums[mid] > nums[mid+1]){
        		return mid;
        	}

        	if(nums[mid] < nums[mid-1] && mid > 0){
        		high = mid - 1;
        	}else{
        		low = mid + 1;
        	}
        }
        return low;
    }
};