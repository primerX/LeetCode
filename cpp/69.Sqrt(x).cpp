class Solution {
public:
    int mySqrt(int x) {
        long long left = 0, right = INT_MAX, mid = 0;
        while(1){
        	mid = left + (right - left) / 2;
        	if(mid * mid <= x && (mid+1) * (mid+1) > x){
        		return mid;
        	}else if(mid * mid > x){
        		right = mid - 1;
        	}else{
        		left = mid + 1;
        	}
        }
    }
};