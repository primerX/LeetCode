// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // 二分查找
        int left = 1, right = n;
        while(left <= right)
        {
        	int mid = left + (right - left)/2;
        	if(isBadVersion(mid)){
        		right = mid - 1;
        	}else{
        		left = mid + 1;
        	}
        }
        return left;
    }
};