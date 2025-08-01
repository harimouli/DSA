class Solution {
public:
    int countPrimes(int n) {
        
        if(n <= 2) return 0;
        int count = n-2;
        vector<int> primes(n, 1);
        for(long long  i = 2; i * i < n; i++){
            if(primes[i]){
                for(long long  j = i * i; j<n; j+=i){
                    if(primes[j]){
                        primes[j] = 0;
                        count -= 1;
                    }
                }
            }
        }

       return count;
    }
};