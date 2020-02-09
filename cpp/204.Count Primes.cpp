class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrimer(n, true);
        for(int i = 2; i * i < n; i++){
            if(isPrimer[i]){
                for(int j = i*i; j < n; j += i){
                    isPrimer[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++){
            if(isPrimer[i]){
                count++;
            }
        }
        return count;
    }
};