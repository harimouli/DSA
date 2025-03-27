class Solution {
public:
    int divide(int dividend, int divisor) {
        


        if(dividend == divisor) return 1;

        bool isPositive = true;

        if(dividend >= 0 && divisor < 0){
            isPositive = false;
        }
        else if(dividend <= 0 && divisor > 0){
            isPositive = false;
        }

        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        if(dividend == INT_MIN && divisor == 1){
            return INT_MIN;
        }
       
        long long  n = abs((long long)dividend);
        long  long d = abs((long long)divisor);


        long long quoient = 0;
        while( n >= d){
            int cnt = 0;

            while(n >= (d << (cnt + 1))){
                cnt++;
            }

            quoient += (1 << cnt);
            n -= (d << cnt);
        }

        if(quoient == (1 << 31) && isPositive){
            return INT_MAX;
        }
        if(quoient == (1 << 31) && !isPositive){
            return INT_MIN;
        }

        return isPositive ? quoient : -1 * quoient;


    }
};