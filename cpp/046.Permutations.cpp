class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        permutation(nums, ret, 0);
        return ret;
    }

    void permutation(vector<int> &nums, vector<vector<int>> &ret, int i){
    	if(i == nums.size() - 1){	//递归边界
    		ret.push_back(nums);
    	}
    	for(int j = i; j < nums.size(); j++){
    		swap(nums[i], nums[j]);
    		permutation(nums, ret, i+1);
    		swap(nums[i], nums[j]);		// 防止重复
    	}
    }
};