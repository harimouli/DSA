class Solution {
public:
    int sum(int num1, int num2) {
        
        
        int result = 0;
        while(num2 != 0){
                result = num1 ^ num2;
                int carry = (num1 & num2) << 1;
                num1 = result;
                num2 = carry;
        }
        return num1;
    }
};