class Solution {
private:
	int target;
	vector<int> nums;
	vector<int> row;
	vector<vector<int>> result;	
public:
	void dfs(int index, int sum){
		if(index > nums.size() - 1) return;
		if(sum == target) result.push_back(row);
		for(int i = index; i < nums.size(); i++){
			if(i == index && (nums[i] > 0 && sum > target || nums[i] < 0 && sum < target)){
				return;
			}
			row.push_back(nums[i]);
			dfs(i, sum + nums[i]);
			row.pop_back();
		}
	}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        nums = candidates;
        this->target = target;
        dfs(0, 0);
        return result;
    }
};