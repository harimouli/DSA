class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();

        string result(len1+len2, '0');


        for(int i = len1-1; i>= 0; i--){
            for(int j = len2 - 1; j>=0; j--){
                    int product = (num1[i] - '0') * (num2[j] - '0') + (result[i+j+1] - '0'); 
                    result[i+j+1] = (product % 10) + '0';
                    result[i+j] += product / 10; 
            }
        }

        for(int i = 0; i<result.size(); i++){
            if(result[i] != '0'){
                return result.substr(i);
            }
        }
        return "0";
    }
};