class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 1) return 0;
        int sum = 0;
        // 最两端的列不用考虑，因为一定不会有水，所以下标从 1 到 length-1
        for(int i = 1; i < height.size()-1; i++){
            int max_left = 0;
            // 找出当前列左边最高的列
            for(int j = i-1; j >= 0; j--){
                if(height[j] > max_left){
                    max_left = height[j];
                }
            }

            int max_right = 0;
            // 找出当前列右边最高的列
            for(int j = i+1; j < height.size(); j++){
                if(height[j] > max_right){
                    max_right = height[j];
                }
            }

            // 找出两端较小的
            int minCol = min(max_left, max_right);
            if(minCol > height[i]){
                sum += (minCol - height[i]);
            }
        }
        return sum;
    }
};