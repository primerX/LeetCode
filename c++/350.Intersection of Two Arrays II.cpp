class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    	// 将数组 num1 和 num2 从小到大排序
    	sort(nums1.begin(), nums1.end()); 
    	sort(nums2.begin(), nums2.end());  
    	// result 用来存储最后的结果
    	vector<int> result;
    	// index 指示 num2 数组的下标
    	int index = 0;
    	bool finished = false;
    	for(int i = 0; i < nums1.size() && !finished; i++){
    		while(index < nums2.size() && nums2[index] < nums1[i]){
    			index++;
    		}
    		if(index == nums2.size()){
    			finished = true;
    		}else if(nums1[i] == nums2[index]){
    			result.push_back(nums1[i]);
    			index++;
    		}
    	}
    	return result;
    }
};