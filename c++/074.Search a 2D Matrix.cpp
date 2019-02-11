class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	// 对每一行都进行二叉搜索
        for(int i = 0; i < matrix.size(); i++)
        	// 利用 binary_search 函数查找某个元素是否出现
            if (binary_search(matrix[i].begin(), matrix[i].end(), target)) return true;
        return false;
    }
};