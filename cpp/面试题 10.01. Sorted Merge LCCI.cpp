class Solution{
public:
	void merge(vector<int>& A, int m, vector<int>& B, int n){
		int idx1 = m-1, idx2 = n-1;
		int cur = m + n - 1;
		while(idx1 >= 0 && idx2 >= 0){
			if(A[idx1] < B[idx2]){
				A[cur--] = B[idx2--];
			}else{
				A[cur--] = A[idx1--];
			}
		}

		if(idx2 >= 0){
			for(int i = 0; i <= idx2; i++){
				A[i] = B[i];
			}
		}
	}

};