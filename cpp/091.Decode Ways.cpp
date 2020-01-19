// 和 Climbing Stairs 很类似，不过需要多加一些判断逻辑
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        int previous = 0, current = 1;
        for(int i = 1; i <= s.length(); i++){
        	if(s[i-1] == '0') current = 0;
        	if(i < 2 || !(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))){
        		previous = 0;
        	}
        	int temp = current;
        	current = previous + current;
        	previous = temp;
        }
        return current;
    }
};