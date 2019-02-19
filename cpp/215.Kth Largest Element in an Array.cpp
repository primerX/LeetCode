class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> s;
        for(int i = 0; i < nums.size(); i++){
        	s.insert(nums[i]);
        	if(s.size() > k){
        		s.erase(s.begin());
        	}
        }
        return *s.begin();
    }
};