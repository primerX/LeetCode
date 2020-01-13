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


// 方法二：从左向右扫描，当遇到重复字母时，以上一个重复字母的 index+1，作为新的搜索起始位置
// 知道最后一个字母，复杂度为O(n)，本质上和方法一一样。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int ASCII_MAX = 255;
        int last[ASCII_MAX];        // 记录字符上次出现的位置
        int start = 0;              // 记录当前子串的起始位置
        int maxLen = 0;
        fill(last, last + ASCII_MAX, -1);   // 因为 0 也是有效位置，所以初始化为 -1

        for(int i = 0; i < s.length(); i++){
            if(last[s[i]] >= start){
                maxLen = max(i - start, maxLen);
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
        }
        return max((int)s.length() - start, maxLen);    //别忘了最后一次，例如"abcd"
    }
};