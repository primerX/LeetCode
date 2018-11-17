class Solution{
public:
	int myAtoi(string str) {
		const int INT_MIN = pow(-2, 31);
		const int INT_MAX = pow(2, 31) - 1;
		if(str.length() == 0){	//字符串长度为 0
			return 0;
		}
		// flag = 1表示该数是整数，flag = 0 表示为负数
		int i = 0, flag = 1;
		while(isspace(str[i])){		//去除字符串的前置空格
			i++;
		}
		if(str[i] == '+' || str[i] == '-'){		//判断是正数还是负数
			if(str[i] == '-') flag = 0;
			i++;
		}
		str = str.substr(i);		//更新字符串 str
		for(int i = 0; i < str.length(); i++){
			if(!isdigit(str[i])){	//碰到第一个非数字字符
				str = str.substr(0, i);
				break;
			}
		}
		if(str.length() == 0){	//字符串中没有数字
			return 0;
		}
		if(str.length() > 10){	//字符串中的数字溢出
			if(flag == 0){		//负数
				return INT_MIN;
			}else{			//正数
				return INT_MAX;
			}
		}
		long long ans = stoll(str);
		if(flag == 0){		//该数为负数
			ans = -ans;
		}
		if(ans < INT_MIN){	//负溢出
			return INT_MIN;
		}else if(ans > INT_MAX){
			return INT_MAX;
		}else{
			return ans;
		}
    }
};