class Solution{
public:
	vector<int> twoSum(vector<int> nums, int target){
		vector<int> result;
		// map 中的 key 放入 target - nums[i];
		// 因此，当我们检查下一个 nums[i] 时，如果 nums[i] 存在于 map 中
		// 意味着我们找到了第二个数
		unordered_map<int, int> mp;
		for(int i = 0; i < nums.size(); i++){
			if(mp.find(nums[i]) == mp.end()){	//没有找到第二个数
				mp[target - nums[i]] = i;
			}else{			//找到了
				result.push_back(mp[nums[i]]);
				result.push_back(i);
				return result;
			}
		}
		
	}
};