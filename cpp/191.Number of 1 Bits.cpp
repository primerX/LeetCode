class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        for(; n > 0; n /= 2){
        	if(n & 0x1) cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        // for(; n > 0; n /= 2){
        // 	if(n & 0x1) cnt++;
        // }
        while(n != 0){
        	if(n & 0x1) cnt++;
        	n /= 2;
        }
        return cnt;
    }
};