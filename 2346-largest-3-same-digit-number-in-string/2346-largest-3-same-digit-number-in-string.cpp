class Solution {
public:
    string largestGoodInteger(string num) {
        

        int n = num.size();
        int left = 0;

        int right = 0;
        string ans = "";
        while(right< n){
            
            if(right - left +  1 > 3 ){
                left++;
            }
           
            if(num[left] == num[left+1] && num[left+1] == num[left+2]){
              if(num.substr(left, 3) > ans) ans = num.substr(left, 3);
            }
           
            right++;
        }
        return ans;
    }
};