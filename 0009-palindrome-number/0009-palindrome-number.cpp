class Solution {
public:
    bool isPalindrome(long long  x) {
        long long  n = x;
        long long   rev = 0;
        while(x > 0)
        {
           int last_digit = x % 10;
            rev = rev * 10 + last_digit;
            x = x /10;
        }
        if(n == rev) return true;
        return false;
    }
};