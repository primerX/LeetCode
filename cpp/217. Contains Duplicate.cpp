class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(auto num : nums){
        	if(mp.find(num) != mp.end()) return true;
        	mp[num] = true;
        }
        return false;
    }
};