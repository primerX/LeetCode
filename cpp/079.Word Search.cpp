class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        for(int i = 0; i < row; ++i){
        	for(int j = 0; j < col; ++j){
        		if(dfs(board, word, 0, i, j, visited)){
        			return true;
        		}
        	}
        }
       	return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int index,
    		 int x, int y, vector<vector<bool>> &visited){
    	if(index == word.size()) return true;	//递归边界
    	if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
    		return false;	// 越界
    	if(visited[x][y] == true) return false;	// 已被访问过，回溯/剪枝
    	if(board[x][y] != word[index]) return false;	// 不相等，回溯/剪枝

    	visited[x][y] = true;
    	bool result = dfs(board, word, index+1, x-1, y, visited)||	// 上
    				  dfs(board, word, index+1, x+1, y, visited)||	// 下
    				  dfs(board, word, index+1, x, y-1, visited)||	// 左
    				  dfs(board, word, index+1, x, y+1, visited);	// 右
    	visited[x][y] = false;
    	return result;
    }
};