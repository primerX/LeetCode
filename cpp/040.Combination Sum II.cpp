class Solution {
private:
	int target;
	vector<int> nums;
	vector<int> row;
	set<vector<int>> s;
	void dfs(int index, int sum){
		if(sum == target){
			s.insert(row);
			return;
		}else if(sum > target){
			return;
		}
		for(int i = index+1; i < nums.size(); i++){
			row.push_back(nums[i]);
			dfs(i, sum + nums[i]);
			row.pop_back();
		}
	}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        nums = candidates;
        this->target = target;
        dfs(-1, 0);
        vector<vector<int>> result;
        for(auto it = s.begin(); it != s.end(); it++){
        	result.push_back(*it);
        }
        return result;
    }
};  