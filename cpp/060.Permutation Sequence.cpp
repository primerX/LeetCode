class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        for(int i = 1; i <= n; i++){
        	result += to_string(i);
        }
        do{
        	k--;
        }while(k>0 && next_permutation(result.begin(), result.end()));
        return result;
    }
};