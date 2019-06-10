class Solution{
public:
	string convert(string s, int numRows)
	{
		
		string temp[numRows];
		// 遍历字符串, 将 Z 字形变换后的字符串存入 temp 数组中
		for(int i = 0; i < s.length();){
			for(int j = 0; j < numRows && i < s.length(); j++){
				temp[j] += s[i++];
			}
			for(int k = numRows-2; k > 0 && i < s.length(); k--){
				temp[k] += s[i++];
			}
		}

		string ans;
		for(int i = 0; i < numRows; i++){
			ans += temp[i];
		}
		return ans;
	}

};