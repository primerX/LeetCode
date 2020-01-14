class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string s;
        generateParenthesis(ret, n, n, s);
        return ret;
    }

    void generateParenthesis(vector<string> &ret, int left, int right, string s){
        if(left == 0 && right == 0){
            ret.push_back(s);
            return;
        }
        if(left > 0){
            generateParenthesis(ret, left-1, right, s + '(');
        }
        if(right > 0 && right > left){
            generateParenthesis(ret, left, right-1, s + ')');
        }
    }
};