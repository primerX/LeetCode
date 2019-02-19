class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        if(n <= 0) return result;
        int row = n, col = n;
        int r, c, cnt = 1;
        for(r=0, c=0; r<(row+1)/2 && c<(col+1)/2; r++, c++){
        	// top
        	for(int i = c; i < col-c; i++){
        		result[r][i] = cnt++;
        	}
        	// right
        	for(int i = r+1; i < row-r; i++){
        		result[i][col-1-c] = cnt++;
        	}
        	// bottom
        	// row-r-1 > r 表示剩下的行数是否 >= 2
        	for(int i = col-2-c; i>=c && row-1-r>r; i--){
        		result[row-1-r][i] = cnt++;
        	}
        	// left
        	// col-1-c > c 表示剩下的列数是否 >= 2
        	for(int i = row-2-r; i>r && col-1-c; i--){
        		result[i][c] = cnt++;
        	}
        }
        return result;
    }
};