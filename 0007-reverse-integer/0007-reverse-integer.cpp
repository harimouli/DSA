class Solution {
public:
    int reverse(int x) {
        long last_digit;
        long  rev = 0;
        while(x!=0)
        {
            last_digit = x % 10;
            rev = rev * 10 + last_digit;
            x = x / 10;
        }
         if(rev>INT_MAX || rev<INT_MIN){
            return 0;
        }
        return rev;
    }
};