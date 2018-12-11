class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	int maxCnt = 0, cnt = 0, ans = nums[0];
    	for(int i = 1; i < nums.size(); i++){
    		if(nums[i] == nums[i-1]){
    			cnt++;
    			if(cnt > maxCnt){
    				maxCnt = cnt;
    				ans = nums[i];
    			}
    		}else{
    			cnt = 0;
    		}
    	}
    	return ans;
    }
};