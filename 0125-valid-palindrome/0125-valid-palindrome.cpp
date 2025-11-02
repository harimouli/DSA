class Solution {
public:
    bool isPalindrome(string s) {
        
        string rs = "";
        for(char c : s){
            if(c >= 'a' && c <= 'z') {
                rs += c;
            }
            if(c >= 'A'  && c <= 'Z'){
                rs += ('a' + (c - 'A'));
            }
            if(c >= '0' && c <= '9'){
                rs += c;
            }
        }
        int n = rs.size();
        int left = 0;
        int right = n - 1;

        while(left <= right){
            if(rs[left] != rs[right]) return false;
            left++;
            right--;
        }
        return true;
        
    }
};