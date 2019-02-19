class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	// 双指针法
        if(nums.size() == 0) return 0;
        int i = 0;		// 初始时 i 指向 nums 的第一个元素
        for(int j = 1; j < nums.size(); j++){
        	if(nums[j] != nums[i]){
        		i++;
        		nums[i] = nums[j];
        	}
        }
        return i + 1;
    }
};