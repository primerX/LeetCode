class Solution {
public:
    bool isPalindrome(string s) {
        s = removeNoise(s);
        for(int i = 0; i < s.size()/2; i++){
            if(s[i] != s[s.size()-i-1]){
                return false;
            }
        }
        return true;
    }

    string removeNoise(string &s){
        string ret;
        for(int i = 0; i < s.size(); i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                ret.push_back(tolower(s[i]));
            }
        }
        return ret;
    }
};