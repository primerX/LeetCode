class Solution {
public:
    bool canJump(vector<int>& nums) {
    	// distance 为能移动的最大距离
        int distance = 0;
        for(int i = 0; i < nums.size() && i <= distance; i++){
        	distance = max(distance, i + nums[i]);
        }
        return distance >= (nums.size() - 1);
    }
};