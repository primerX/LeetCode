class Solution {
public:
    void sortColors(vector<int>& nums) {
        int last = nums.size() - 1;
        for(int i = 0, j = 0; i <= last; i++){
        	if(nums[i] == 0){
        		swap(nums[i], nums[j++]);
        	}
        	if(nums[i] == 2){
        		swap(nums[i--], nums[last--]);
        	}
        }
    }
};