class Solution{
public:
	int lengthOfLongestSubstring(string s){
		//使用 two point 和 hashTable 方法
		int i = 0, j = 0, len = s.length();
		int maxlen = 0;		//最大长度
		int hashTable[128] = {0};		//标记字母a~z, A~Z是否出现过
		while(j < len){
			if(hashTable[s[j]] == 0){		//字母还未出现
				hashTable[s[j]] = 1;
			}else{			// 字母出现过
				maxlen = max(maxlen, j - i);
				while(s[i] != s[j]){		
					hashTable[s[i]] = 0;
					i++;
				}
				i++;
			}
			j++;
		}
		return max(maxlen, j-i);
	}
};