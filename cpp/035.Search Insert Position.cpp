class Solution {
public:
	int binary_search(const vector<int> &nums, int target){
		int low = 0, high = nums.size() - 1;
		while(low <= high){
			int mid = low + (high - low) / 2;
			if(nums[mid] == target){
				return mid;
			}else if(target > nums[mid]){
				low = mid + 1;
			}else{
				high = mid - 1;
			}
		}
		return low;
	}

    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        return binary_search(nums, target);
    }
};