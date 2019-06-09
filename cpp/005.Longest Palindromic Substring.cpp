class Solution{
public:
	string longestPalindrome(string s){
        int len = s.length();
		if(s.length() < 1){
			return "";
		}
		string ans = s.substr(0,1);	//初始化 ans 为 s 的第一个字符
		for(int i = 0; i < s.length(); i++){
			// 当回文串字符个数为奇数时
			string temp = midToSlid(s, i, i);
			if(temp.length() > ans.length()){
				ans = temp;
			}

			// 当回文串字符个数为偶数时
			temp = midToSlid(s, i, i + 1);
			if(temp.length() > ans.length()){
				ans = temp;
			}
		}
		return ans;
	}

	string midToSlid(string s, int left, int right){
		while(left >= 0 && right <= s.length()-1 && s[left] == s[right]){
			left--;
			right++;
		}
		// substr() 函数第二个参数为 长度
		return s.substr(left + 1, right - left - 1);
	}
	

};