class Solution {
public:
    int calPoints(vector<string>& ops) {
    	stack<int> st;
    	for(int i = 0; i < ops.size(); i++){
    		if(ops[i] == "C"){
    			if(!st.empty()) st.pop();		//栈不为空
    		}else if(ops[i] == "D"){
    			st.push(2 * st.top());
    		}else if(ops[i] == "+"){
                if(!st.empty()){
                    int top = st.top();
    			    st.pop();
                    int newtop = st.top() + top;
    				st.push(top);
    				st.push(newtop);
                }
    		}else{
    			st.push(stoi(ops[i]));
    		}
    	}
    	int ret = 0;
    	while(!st.empty()){
    		ret += st.top();
    		st.pop();
    	}
    	return ret;
    }
};