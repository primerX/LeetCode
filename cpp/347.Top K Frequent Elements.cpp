class Solution {
public:
	static int cmp(const pair<int, int> &x, const pair<int, int> &y){
		return x.second > y.second;
	}

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        unordered_map<int, int> mp;
        vector<pair<int, int>> pair_vec;
        for(int i = 0; i < nums.size(); i++){
        	mp[nums[i]]++;
        }
        for(unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
        	pair_vec.push_back({it->first, it->second});
        }

        sort(pair_vec.begin(), pair_vec.end(), cmp);
        vector<pair<int, int>>::iterator curr = pair_vec.begin();
        while(k--){
        	v.push_back(curr->first);
        	curr++;
        }
        return v;
    }
};