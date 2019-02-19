class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	const int MAX = amount + 1;
        // dp[i] 表示凑成金额 i 所需要的最小硬币个数
        vector<int> dp(amount + 1, MAX);
        dp[0] = 0;
        // i 表示金额
        for(int i = 1; i <= amount; i++){
        	for(int j = 0; j < coins.size(); j++){
        		if(i >= coins[j]){
        			// dp[i-coins[j]] 表示剩下的金额所需要的金币数
        			dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        		}
        	}
        }
        return dp[amount] == MAX ? -1 : dp[amount];
    }
};