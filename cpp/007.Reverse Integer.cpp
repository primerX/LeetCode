class Solution{
public:
	int reverse(int x){
		int ans = 0, temp = 0;
		while(x != 0){
			temp = x % 10;
            // 防止溢出
            if(ans > INT_MAX/10 || ans < INT_MIN/10){
				return 0;
			}
			ans = ans * 10 + temp;
			x /= 10;
		}
		return ans;
	}
};