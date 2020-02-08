class Solution{
public:
	// 比较函数
	static bool cmp(string& s1, string &s2){ 
		return s1+s2 > s2+s1;
	}

	string largestNumber(vector<int>& nums){
		// 将 int 转换为 string
		vector<string> v;
		for(int i = 0; i < nums.size(); i++){
			v.push_back(to_string(nums[i]));
		}

		sort(v.begin(), v.end(), cmp);

		string result;
		for(int i = 0; i < v.size(); i++){
			result += v[i];
		}

		if(result[0] == '0') return "0";

		return result;
	}

};