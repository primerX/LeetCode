class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        /* 自顶向下，考虑边界条件要特殊处理 , minPath[i][j] = Min(minPath[i-1][j-1], minPath[i-1][j]) + a[i][j], 
        最左、右列要特殊处理
        最左： minPath[i][j] = minPath[i-1][j] + a[i][j]
        最右： minPath[i][j] = minPath[i-1][j-1] + a[i][j]
        */      
        int rowSize = triangle.size();
        vector<vector<int>> minPath(triangle);
        if (rowSize == 1) {
            return triangle[0][0];
        }

        minPath[0][0] = triangle[0][0];
        minPath[1][0] = minPath[0][0] + triangle[1][0];
        minPath[1][1] = minPath[0][0] + triangle[1][1];
        
        for(int i=2;i<triangle.size();i++) {
            for(int j=0;j<triangle[i].size();j++) {
                                
                // 最左侧
                if(j==0)  minPath[i][j] = minPath[i-1][j] + triangle[i][j];
                // 最右侧
                else if(j==triangle[i].size()-1)  minPath[i][j] = minPath[i-1][j-1] + triangle[i][j];
                else  minPath[i][j] = min(minPath[i-1][j-1], minPath[i-1][j]) + triangle[i][j];                            
            }
        }
        // c++11新方法 max/ min_element 的使用请注意，不需要sort再打印了
        return *std::min_element(minPath[rowSize-1].begin(), minPath[rowSize-1].end() ) ;
    }
};