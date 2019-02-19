class Solution{
public:
	int reverse(int x){
		string s = to_string(x);	//变为字符串
		if(s[0] == '-'){		//负数
			std::reverse(s.begin() + 1, s.end());
		}else{
			std::reverse(s.begin(), s.end());
		}
		long long temp = stoll(s);		//将 s 转换成 long long 型的整数
		if(temp > pow(2, 31) - 1 || temp < pow(-2, 31)){
			//判断是否溢出
			return 0;
		}
		return temp;
	}
};