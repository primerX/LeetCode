// DFS - Deepth First Search
//    
//   For example: "aaba"
//    
//                     +------+           
//              +------| aaba |-----+     
//              |      +------+     |     
//            +-v-+              +-v--+  
//            | a |aba           | aa |ba
//        +---+---+--+           +--+-+  
//        |          |              |    
//      +-v-+     +--v--+         +-v-+  
//      | a |ba   | aba |\0       | b |a 
//      +-+-+     +-----+         +-+-+  
//        |        a, aba           |    
//      +-v-+                     +-v-+  
//      | b |a                    | a |\0
//      +-+-+                     +---+  
//        |                      aa, b, a
//      +-v-+                            
//      | a |\0                          
//      +---+                            
//    a, a, b, a                         
//

class Solution {
public:
	bool isPalindrome(string &s, int start, int end){
		while(start < end){
			if(s[start] != s[end]){
				return false;
			}
			start++; end--;
		}
		return true;
	}


	void partitionHelper(string &s, int start, vector<string> &output, vector<vector<string>> &result){
		if(start == s.size()){
			result.push_back(output);
			return;
		}
		for(int i = start; i < s.size(); i++){
			if(isPalindrome(s, start, i)){
				//把当前回文子串放入 output 中
				output.push_back(s.substr(start, i-start+1));
				// 递归检查剩下的子串
				partitionHelper(s, i+1, output, result);
				// 为了获得更长的子串，需要取出当前的回文子串
				output.pop_back();
			}
		}
	}

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> output;
        partitionHelper(s, 0, output, result);
        return result;
    }
};