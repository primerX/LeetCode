class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	// bFirstColZero 用来标记矩阵第一列中是否出现 0
        bool bFirstColZero = false;
        int row = matrix.size(), col = matrix[0].size();

        for(int i = 0; i < row; i++){
        	if(matrix[i][0] == 0) bFirstColZero = true;
        	for(int j = 1; j < col; j++){
        		if(matrix[i][j] == 0){
        			matrix[i][0] = matrix[0][j] = 0;
        		}
        	}
        }

        for(int i = row-1; i >= 0; i--){
        	for(int j = col-1; j > 0; j--){
        		if(matrix[i][0] == 0 || matrix[0][j] == 0){
        			matrix[i][j] = 0;
        		}
        	}
        	if(bFirstColZero == true){
        		matrix[i][0] = 0;
        	}
        }
    }
};