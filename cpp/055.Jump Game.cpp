class Solution {
public:
    bool canJump(vector<int>& nums) {
    	// max_distance 为能移动的最大距离
        int max_distance = 0;
        for(int i = 0; i < nums.size() && i <= max_distance; i++){
        	max_distance = max(max_distance, i + nums[i]);
        }
        return max_distance >= (nums.size() - 1);
    }
};