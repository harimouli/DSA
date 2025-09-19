class Solution {
public:

    double pow(double x, long long num){
         if(num == 0) return 1;
         if(num == 1) return x;
         if(num % 2) {
            return x * pow(x  , num -1);
         }
         return pow(x* x , num / 2);
    }
    double myPow(double x, int n) {
        long long num = n;

        if(n < 0) {
            x = 1 / x;
            num = -1LL * n;
        }
        return pow(x, num);
    }
};