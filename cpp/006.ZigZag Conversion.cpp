class Solution{
public:
	string convert(string s, int numRows)
	{
		string temp[numRows];
		int i = 0;
		while(i < s.length())
		{
			for(int j = 0; j < numRows && i < s.length(); j++){
				temp[j] += s[i++];
			}
			for(int k = numRows-2; k > 0 && i < s.length(); k--){
				temp[k] += s[i++];
			}
		}
		string result;
		for(int j = 0; j < numRows; j++){
			result += temp[j];
		}
		return result;
	}

};