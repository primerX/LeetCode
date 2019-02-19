class Solution {
public:
    int numTrees(int n) {
        long long res = 1;
        // 公式--- 卡特兰数
        for(int i = 1; i <= n; i++){
        	res = res*2*(2*i-1) / (i+1);
        }
        return res;
    }
};