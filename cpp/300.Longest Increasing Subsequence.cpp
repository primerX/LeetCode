class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if(nums.size() == 0) return 0;
    	// v 用来存储最长不下降子序列的元素
        vector<int> v;
        v.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
        	if(nums[i] > v.back()){
        		v.push_back(nums[i]);
        	}else{
        		// 找到第一个比 num[i] 大的位置，将该位置的数替换为 nums[i]
        		*lower_bound(v.begin(), v.end(), nums[i]) = nums[i];
        	}
        }
        return v.size();
    }
};