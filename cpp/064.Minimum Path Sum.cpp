class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() <= 0) return 0;

        for(int row = 0; row < grid.size(); row++){
        	for(int col = 0; col < grid[0].size(); col++){
        		if(row == 0 && col == 0) continue;
        		else if(row == 0) grid[row][col] += grid[row][col-1];
        		else if(col == 0) grid[row][col] += grid[row-1][col];
        		else grid[row][col] += std::min(grid[row-1][col], grid[row][col-1]);
        	}
        }

        return grid[grid.size()-1][grid[0].size()-1];
    }
};