class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) return false;
        return pow(3, (round)(log(n)/log(3))) == n;
    }
};