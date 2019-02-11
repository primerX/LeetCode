class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 0));

        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        // 判断网格边缘是否有障碍物
        for(int r = 1; r < row; r++){
        	dp[r][0] = obstacleGrid[r][0] == 1 ? 0 : dp[r-1][0];
        }
        for(int c = 1; c < col; c++){
        	dp[0][c] = obstacleGrid[0][c] == 1 ? 0 : dp[0][c-1];
        }

        // 判断网格内部是否有障碍物
        for(int r = 1; r < row; r++){
        	for(int c = 1; c < col; c++){
        		dp[r][c] = obstacleGrid[r][c] == 1 ? 0 : dp[r][c-1]+dp[r-1][c];
        	}
        }

        return dp[row-1][col-1];
    }
};