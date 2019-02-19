class Solution {
public:
    bool isAnagram(string s, string t) {
		// hashTable[26] 用来记录 26 个字母出现的次数
		int hashTable[26] = {0};
		if(s.length() != t.length()){
			return false;
		}
		for(int i = 0; i < s.length(); i++){
			hashTable[s[i] - 'a']++;
		}
		for(int i = 0; i < t.length(); i++){
			hashTable[t[i] - 'a']--;
		}
		for(int i = 0; i < 26; i++){
			if(hashTable[i] != 0){
				return false;
			}
		}
		return true;
    }
};