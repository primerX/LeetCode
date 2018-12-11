class Solution {
public:
    double myPow(double x, int n) {
        if(!n) return 1;
        // 将 pow(x, n/2) 记录下来，时间复杂度可以优化值 O(logn)
        double temp = myPow(x, n/2);
        if(n & 1){		// 奇数
        	if(n > 0){
        		return x * temp * temp;
        	}else{
        		return temp * temp / x;
        	}
        }else{		// 偶数
        	return temp * temp;
        }
    }
};