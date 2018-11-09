class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    	vector<int> result;		//用来存储返回的结果
    	// mp 用来存储 nums 中每一个元素以及对应的下一个最大元素构成的映射
        map<int, int> mp;		
        stack<int> st;
        for(int i = nums.size()-1; i >= 0; i--){
       	 	while(!st.empty() && st.top() <= nums[i]) st.pop();
       		mp[nums[i]] = st.empty() ? -1 : st.top();
       		st.push(nums[i]);
        }
        for(int i = 0; i < findNums.size(); i++){
       		result.push_back(mp[findNums[i]]);
        }
        return result;
    }
};