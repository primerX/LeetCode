class Solution {
public:
    int lengthOfLastWord(string s) {
    	// flag 表示是否出现字母
        int cnt = 0, flag = 0;
        for(int i = s.length()-1; i >= 0; i--){
        	if(flag == 0 && s[i] == ' '){
        		continue;
        	}else if(s[i] != ' '){
        		flag = 1;
        		cnt++;
        	}else{          // 已经出现过单词
                break;
            }
        }
        return cnt;
    }
};