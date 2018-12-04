class Solution {
public:
    int countPrimes(int n) {
        vector<int> book(n, 1);
        for(int i = 2; i * i < n; i++){
            if(book[i] == 1){
                for(int j = i*i; j < n; j += i){
                    book[j] = 0;
                }
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++){
            if(book[i] == 1){
                count++;
            }
        }
        return count;
    }
};