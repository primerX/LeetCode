class Solution {
public:
    bool isHappy(int n) {
    	int cnt = 0;	// 计数器
        while(n != 1){
        	cnt++;
        	int temp = 0;
        	while(n != 0){
        		temp = temp + (n % 10) * (n % 10);
        		n /= 10;
        	}
        	n = temp;
        	if(cnt == 10){
        		return false;
        	}
        }
        return true;
    }
};