class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	int len = nums.size();			// 最终结果的大小
    	int size = pow(2, len);
        vector<vector<int>> ret(size);
        for(int i = 0; i < size; i++){
        	for(int j = 0; j < len; j++){
        		if((i >> j) & 1) {
        			ret[i].push_back(nums[j]);
        		}
        	}
        }
        return ret;
    }
};