class Solution {
public:
    
    int totalMoney(int n) {

            if(n <= 7) {
                return (n * (n+1)) / 2;
            }
            int start = 0;
            int end = 7;
            int res = 0;
             while(n >= 7) {
                int sum = (end * (end + 1)) / 2;
                res += (sum - (start * (start + 1))/ 2);
                end++;
                start++;
                n -= 7; 
             }
        
            if(n!= 0) {
                int num = start + n;
                int sum = (num * (num + 1)) / 2;
                res += (sum - (start * (start + 1))/ 2);
               
            }
             return res;

    }
};