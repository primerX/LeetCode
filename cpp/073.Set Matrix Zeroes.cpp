class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	bool *row = new bool[matrix.size()]();
        bool *col = new bool[matrix[0].size()]();
        for(int r = 0; r < matrix.size(); ++r){
            for(int c = 0; c < matrix[0].size(); ++c){
                if(matrix[r][c] == 0){
                    row[r] = true;
                    col[c] = true;
                }
            }
        }

        for(int r = 0; r < matrix.size(); ++r){
            for(int c = 0; c < matrix[0].size(); ++c){
                if(row[r] || col[c]){
                    matrix[r][c] = 0;
                }
            }
        }
    }
};