class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	// 最长子串的长度，	最后一个重复字符的位置
        int maxLen = 0, lastRepeatPos = -1;

        // mp 用来存储字符与位置之间的关系
        unordered_map<char, int> mp;

        for(int i = 0; i < s.length(); i++){
        	// 更新最后一个重复字符的位置，后面一条语句是为了防止 "abba" 这种情况
        	if(mp.find(s[i]) != mp.end() && lastRepeatPos < mp[s[i]]){
        		lastRepeatPos = mp[s[i]];
        	}
        	// 更新最长子串的长度
        	if(i - lastRepeatPos > maxLen){
        		maxLen = i - lastRepeatPos;
        	}
        	mp[s[i]] = i;
        }
        return maxLen;
    }
};