class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	// 避免一开始是 int 的最大值，加了数之后溢出的情况
        long long result = INT_MAX;
        // 将 nums 数组从小到大排序
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
        	int begin = i + 1, end = n - 1;
        	while(begin < end){
        		int sum = nums[i] + nums[begin] + nums[end];
        		if(sum == target){
        			begin++;
        			end--;
        		}else if(sum > target){
        			end--;
        		}else{
        			begin++;
        		}
        		// 取最接近的最小值
        		if(abs(sum - target) < abs(result - target)){
        			result = sum;
        		}
        	}
        }
        return result;
    }
};