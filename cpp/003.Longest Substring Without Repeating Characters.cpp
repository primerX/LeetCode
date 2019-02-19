class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, lastTRepeatPos = -1;
        unordered_map<char, int> mp;

        for(int i = 0; i < s.length(); i++){
        	if(mp.find(s[i]) != mp.end() && lastTRepeatPos < mp[s[i]]){
        		lastTRepeatPos = mp[s[i]];
        	}
        	if(i - lastTRepeatPos > maxLen){
        		maxLen = i - lastTRepeatPos;
        	}
        	mp[s[i]] = i;
        }
        return maxLen;
    }
};