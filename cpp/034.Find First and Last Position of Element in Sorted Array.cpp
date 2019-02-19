class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high && nums[low] != target && nums[high] != target){
        	int mid = low + (high - low) / 2;
        	if(nums[mid] < target){
        		low = mid + 1;
        	}else if(nums[mid] > target){
        		high = mid - 1;
        	}else{
        		break;
        	}
        }
        vector<int> ret(2);
        if(low > high){
            ret[0] = -1; ret[1] = -1;
        	return ret;
        }
        while(nums[low] != target){
        	low++;
        }
        while(nums[high] != target){
        	high--;
        }
        ret[0] = low; ret[1] = high;
        return ret;
    }
};