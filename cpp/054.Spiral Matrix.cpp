class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int row = matrix.size();
        if(row <= 0) return ret;
        int col = matrix[0].size();
        if(col <= 0) return ret;
        int r, c;
        for(r = 0, c = 0; r < (row+1)/2 && c < (col+1)/2; r++, c++){
        	// 上
        	for(int i = c; i < col - c; i++){
        		ret.push_back(matrix[r][i]);
        	}
        	// 右
        	for(int i = r+1; i < row-r; i++){
        		ret.push_back(matrix[i][col-c-1]);
        	}
        	// 下
        	for(int i = col-c-2; row-r-1 > r && i >= c; i--){
        		ret.push_back(matrix[row-r-1][i]);
        	}
        	// 左
        	for(int i = row-r-2; col-c-1 > c && i > r; i--){
        		ret.push_back(matrix[i][c]);
        	}
        }
        return ret;
    }
};