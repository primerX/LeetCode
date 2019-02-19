class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = pow(2, 31) - 1;
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++){
        	if(minprice > prices[i]){
        		minprice = prices[i];
        	}else if(prices[i] - minprice > maxProfit){
        		maxProfit = prices[i] - minprice;
        	}
        }
        return maxProfit;
    }
};