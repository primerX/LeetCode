class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int n = nums.size();
        if(n < 3) return n;
        int pos = 0, cnt = 1;
        for(int i = 1; i < n; i++){
        	if(nums[i] == nums[pos]){
        		cnt++;
        		if(cnt == 2){
        			nums[++pos] = nums[i];
        		}
        	}else{
        		cnt = 1;
        		nums[++pos] = nums[i];
        	}
        }
        return pos+1;
    }
};