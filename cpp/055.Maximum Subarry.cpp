class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int maxSum = nums[0], thisSum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(thisSum >= 0){
                thisSum = thisSum + nums[i];
            }else{
                thisSum = nums[i];
            }
            maxSum = max(maxSum, thisSum);
        }
        return maxSum;
    }
};