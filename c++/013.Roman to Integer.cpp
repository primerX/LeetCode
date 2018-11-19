class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        // 用来映射罗马字符和数字之间的关系
        map<char, int> mp;
        char c[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int t[] = {1, 5, 10, 50, 100, 500, 1000};
        // 完成罗马字符与数字之间的映射
        for(int i = 0; i < 7; i++){
        	mp.insert(pair<char, int> (c[i], t[i]));
        }
        for(int i = 0; i < s.length() - 1; i++){
        	if(mp[s[i]] >= mp[s[i + 1]]){
        		ans += mp[s[i]];
        	}else{
        		ans -= mp[s[i]];
        	}
        }
        // 加上最后一个字符所对应的数字
        ans += mp[s[s.length() - 1]];
        return ans;
    }
};