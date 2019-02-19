class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){
        	int mid = low + (high - low) / 2;
        	if(nums[mid] == target) return mid;
        	// mid 在旋转结点的右边
        	if(nums[mid] < nums[low]){	
        		if(target > nums[mid] && target <= nums[high]){
        			low = mid + 1;
        		}else{
        			high = mid - 1;
        		}
        	}else if(nums[mid] > nums[high]){
        		// mid 在旋转结点的左边
        		if(target >= nums[low] && target < nums[mid]){
        			high = mid - 1;
        		}else{
        			low = mid + 1;
        		}
        	}else{		// target 在正确的区间
        		if(target < nums[mid]){
        			high = mid - 1;
        		}else{
        			low = mid + 1;
        		}
        	}
        }
        return -1;
    }
};