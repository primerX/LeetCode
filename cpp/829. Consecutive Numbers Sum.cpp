class Solution{
public:
	int consecutiveNumbersSum(int N){
		int ans = 0;
		for(int i = 1; N > 0; i++){
			ans += (N % i == 0);
			N -= i;
		}
        return ans;
	}

};