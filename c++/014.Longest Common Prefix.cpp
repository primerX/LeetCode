class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){	// 字符串数组为空
        	return "";
        }
        string ans = strs[0];
        for(int i = 1; i< strs.size(); i++){
        	for(int j = 0; j < ans.length(); j++){
        		if(strs[i][j] != ans[j]){
        			ans = ans.substr(0, j);
        			break;
        		}
        	}
        }
        return ans;
    }
};