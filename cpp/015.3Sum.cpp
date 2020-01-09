class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;		// 定义结果集(二维数组)
        sort(nums.begin(), nums.end());	//将 nums 从小到大排序
        int n = nums.size();
        for(int i = 0; i < n; i++){
        	// 当出现 num[i] > 0 的情况，直接退出
        	if(nums[i] > 0) break;
        	if(i > 0 && nums[i] == nums[i-1]) continue;
        	int begin = i + 1, end = n - 1;
        	while(begin < end)
        	{
        		int sum = nums[i] + nums[begin] + nums[end];
        		vector<int> temp;
	        	if(sum == 0){
	        		temp.push_back(nums[i]);
	        		temp.push_back(nums[begin]);
	        		temp.push_back(nums[end]);
	        		result.push_back(temp);
	        		begin++;
	        		end--;
	        		while(begin < end && nums[begin] == nums[begin-1]) begin++;
	        		while(begin < end && nums[end] == nums[end+1]) end--;
	        	}else if(sum > 0){
	        		end--;
	        	}else{
	        		begin++;
	        	}
        	}
        }
        return result;
    }  
};