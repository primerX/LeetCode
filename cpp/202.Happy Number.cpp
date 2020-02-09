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

// 使用“快慢指针”思想找出循环
class Solution{
public:
    int bitSquareSum(int n){
        int sum = 0;
        while(n > 0){
            int temp = n % 10;
            sum += temp * temp;
            n /= 10;
        }
        return sum;

    }

    bool isHappy(int n){
        int slow = n, fast = n;
        do{
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        }while(slow != fast);
        return slow == 1;
    }

};