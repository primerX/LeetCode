class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        int aindex = m - 1;
        int bindex = n - 1;
        while(aindex >= 0 && bindex >= 0)
        {
        	if(nums1[aindex] <= nums2[bindex]){
        		nums1[index--] = nums2[bindex--];
        	}else{
        		nums1[index--] = nums1[aindex--];
        	}
        }
        while(bindex >= 0){
            nums1[index--] = nums2[bindex--];
        }
    }
};