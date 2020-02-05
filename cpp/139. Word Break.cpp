class Solution {
public:
    bool wordBreak(string s, set<string>& wordDict) {
    	//using an array to mark subarray from 0 to i can be broken or not
        vector<bool> v(s.size(), false);

        for(int i = 0; i < s.size(); i++){
        	string w = s.substr(0, i+1);
        	v[i] = (wordDict.find(w) != wordDict.end());

        	if(v[i]) continue;

        	for(int j = 0; j < i; j++){
        		if(v[j] == true){
        			w = s.substr(j+1, i-j);
        			v[i] = (wordDict.find(w) != wordDict.end());
        			if(v[i]) break;
        		}
        	}
        }
        return v.size() ? v[v[size()-1]] : false;
    }
};