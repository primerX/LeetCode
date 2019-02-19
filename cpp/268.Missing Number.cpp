class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int ret = 0;
    	for(int i = 0; i < nums.size(); i++){
    		ret = ret ^ nums[i];
    	}
    	for(int i = 1; i <= nums.size(); i++){
    		ret = ret ^ i;
    	}
    	return ret;
    }
};