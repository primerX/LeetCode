class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty()) return ret;
        int beginX = 0, endX = matrix[0].size() - 1;
        int beginY = 0, endY = matrix.size() - 1;
        while(true){
            // 从左向右
            for(int col = beginX; col <= endX; ++col) ret.push_back(matrix[beginY][col]);
            if(++beginY > endY) break;

            // 从上到下
            for(int row = beginY; row <= endY; ++row) ret.push_back(matrix[row][endX]);
            if(beginX > --endX) break;

            // 从右向左
            for(int col = endX; col >= beginX; --col) ret.push_back(matrix[endY][col]);
            if(beginY > --endY) break;

            // 从下到上
            for(int row = endY; row >= beginY; --row) ret.push_back(matrix[row][beginX]);
            if(++beginX > endX) break;
        }
        return ret;
    }
};