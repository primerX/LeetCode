class Solution {
private:
	int n, k;
	vector<vector<int>> result;
	vector<int> row;
public:
	// 利用深度优先搜索（DFS）求解问题
	void dfs(int cur, int cnt){
		if(cnt == k){
			result.push_back(row);
			return;
		}
		for(int i = cur + 1; i <= n; i++){
			row.push_back(i);
			dfs(i, cnt+1);
			// 将当前元素 pop_back() 出来
			row.pop_back();
		}
	}

    vector<vector<int>> combine(int n, int k) {
        this->n = n, this->k = k;
        dfs(0, 0);
        return result;
    }
};