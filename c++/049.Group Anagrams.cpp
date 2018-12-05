class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;

        unordered_map<string, vector<string>> mp;
        for(auto s : strs){
        	string t = s;
        	sort(t.begin(), t.end());
        	mp[t].push_back(s);
        }

        for(auto m : mp){
        	vector<string> temp = {m.second.begin(), m.second.end()};
        	ret.push_back(temp);
        }

        return ret;
    }
};