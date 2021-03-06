class Solution {
public:
	// 从右向左
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> array;
        for(int i = 1; i <= numRows; i++){
        	for(int j = i-2; j > 0; j--){
        		array[j] = array[j] + array[j-1];
        	}
        	array.push_back(1);
        	result.push_back(array);
        }
        return result;
    }
};