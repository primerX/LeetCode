class Solution {
public:
    bool isPalindrome(string s) {
        // 空字符串
        if(s.length() == 0){
            return true;
        }
        int i = 0, j = s.length() - 1;
        while(i < j)
        {
            while(i < j && !isalnum(s[i])){
                i++;
            }
            while(i < j && !isalnum(s[j])){
                j--;
            }
            if(i < j && tolower(s[i]) != tolower(s[j])){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};