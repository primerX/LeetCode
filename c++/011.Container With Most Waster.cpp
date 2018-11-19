class Solution {
public:
    int maxArea(vector<int>& height) {
        // 初始时最大面积为 0，用 two pointer 方法
        int maxarea = 0, left = 0, right = height.size() - 1;
        while(left < right){
            maxarea = max((right - left) * min(height[left], height[right]), maxarea);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        
        return maxarea;
    }
};