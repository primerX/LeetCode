// 解法一: 利用异或方法, 是一种更好的方法
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 利用异或运算, 两个相同数异或结果为 0
        int result = 0;
        for(const auto& val : nums){
            result = result^val;
        }
        return result;
    }
};

// 解法二:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	// 对数组进行排序
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i += 2){
        	if(nums[i] != nums[i+1]){
        		return nums[i];
        	}
        }
        return nums[nums.size()-1];
    }
};