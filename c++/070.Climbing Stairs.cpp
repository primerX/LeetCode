class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3) return n;
        int a[2] = {2, 3};
        for(int i = 4; i <= n; i++){
        	t = a[0] + a[1];
        	a[0] = a[1];
        	a[1] = t;
        }
        return t;
    }
};