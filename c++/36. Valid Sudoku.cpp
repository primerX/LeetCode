class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    	// 9 x 9
        const int cnt = 9;
        // 用来标记每一行中数字 1~9 是否出现
        bool row_mask[cnt][cnt] = {false};
        // 用来标记每一列中数字 1~9 是否出现
        bool col_mask[cnt][cnt] = {false};
        // 用来标记每个区块数字 1~9 是否出现
        bool area_mask[cnt][cnt] = {false};

        // 遍历每一行和每一列
        for(int r = 0; r < board.size(); r++){
        	for(int c = 0; c < board[r].size(); c++){
        		if(!isdigit(board[r][c])) continue;
        		int idx = board[r][c] - '0' - 1;

        		// 检查行
        		if(row_mask[r][idx] == true){
        			return false;
        		}
        		row_mask[r][idx] = true;

        		// 检查列
        		if(col_mask[c][idx] == true){
        			return false;
        		}
        		col_mask[c][idx] = true;

        		// 检查区块
        		int area = (r/3) * 3 + (c/3);
        		if(area_mask[area][idx] == true){
        			return false;
        		}
        		area_mask[area][idx] = true;
        	}
        }
        return true;
    }
};