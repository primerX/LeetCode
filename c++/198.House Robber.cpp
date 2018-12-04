class Solution {
public:
    int rob(vector<int>& nums) {
        // n1 表示 dp[i-1], n2 表示 dp[i-2]
        int n1 = 0, n2 = 0;
        
        for(int i = 0; i < nums.size(); i++){
            int current = max(n1, n2 + nums[i]);
            n2 = n1;
            n1 = current;
        }
        return n1;
    }
};