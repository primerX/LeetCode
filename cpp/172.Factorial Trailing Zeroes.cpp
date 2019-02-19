class Solution {
public:
	// 0 的个数为因子中 5 的个数
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n != 0){
        	cnt += n / 5;
        	n /= 5;
        }
        return cnt;
    }
};