class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        bool flag = false;
        if(nums.size()){
        	// second 为 INT_MAX
        	int first = nums[0], second = pow(2, 31) - 1;
        	for(int i = 1; i < nums.size(); i++){
        		if(nums[i] > second){
        			flag = true;
        			break;
        		}else if(nums[i] > first && nums[i] < second){
        			second = nums[i];
        		}else if(nums[i] < first){
        			first = nums[i];
        		}
        	}
        }
        return flag;
    }
};