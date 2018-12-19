class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;

        for(int i = nums.size()-1; i > 0; i--){
        	if(nums[i-1] < nums[i]){
        		int j = nums.size() - 1;
        		while(nums[i-1] >= nums[j]){
        			j--;
        		}
        		swap(nums[i-1], nums[j]);
        		reverse(nums.begin() + i, nums.end());
        		return;
        	}
        	// 4 3 2 1 的情况
        	if(i == 1){
        		reverse(nums.begin(), nums.end());
        		return;
        	}
        }
    }
};