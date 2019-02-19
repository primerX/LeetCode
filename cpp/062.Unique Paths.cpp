class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m > n) swap(m, n);
        if(m < 2) return m;
        vector<int> step(n, 1);
        for(int i = 1; i < m; i++){
        	for(int j = 1; j < n; j++){
        		step[j] += step[j-1];
        	}
        }
        return step[n-1];
    }
};