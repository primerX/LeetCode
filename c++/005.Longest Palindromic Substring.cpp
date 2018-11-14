class Solution{
public:
	string longestPalindrome(string s){
		int len = s.length();
		if(len == 0){		// 字符串 s 为空
			return "";
		}
		string ans = s.substr(0, 1);		//初始,ans等于字符串的第一个字母
		for(int i = 0; i < len - 1; i++){
			//当最长回文子串是奇数时
			string temp = midToSide(s, i, i);
			if(temp.length() > ans.length()){
				ans = temp;		//更新最长的回文子串
			}
			//当最长回文子串是偶数时
			temp = midToSide(s, i, i+1);
			if(temp.length() > ans.length()){
				ans = temp;		//更新最长的回文子串
			}
		}
		return ans;
	}

	// 对于每个元素都从两边寻找是否有回文子串
	string midToSide(string s, int left, int right)
	{
		while(left >= 0 && right <= s.length()-1 && s[left] == s[right]){
			left--;
			right++;
		}
		return s.substr(left + 1, right - left - 1);
	}

};