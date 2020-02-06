class Solution {
public:
    //由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值imin，
    int maxProduct(vector<int>& nums) {
        int maxValue = INT_MIN, imax = 1, imin = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                int tmp = imax;
                imax = imin;
                imin = tmp;
            }
            imax = max(imax*nums[i], nums[i]);
            imin = min(imin*nums[i], nums[i]);
            maxValue = max(maxValue, imax);
        }
        return maxValue;
    }
};