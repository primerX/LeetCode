class Solution {
public:
    // 逆序 nums 数组在 [start, end] 区间中的元素
    void reverseArray(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        } 
    }
    
    void rotate(vector<int>& nums, int k) {
        // n 为数组 nums 的大小
        int n = nums.size();
        k = k % n;
        // 逆序 nums 数组在 [n-k, n-1] 区间中的元素
        reverseArray(nums, n - k, n - 1);
        // 逆序 nums 数组在 [0, n-k-1] 区间中的元素
        reverseArray(nums, 0, n - k - 1);
        // 逆序 nums 数组在 [0, n-1] 区间中的元素
        reverseArray(nums, 0, n - 1);
    }
};