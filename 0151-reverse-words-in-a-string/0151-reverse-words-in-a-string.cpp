class Solution {
public:
    string reverseWords(string s) {
        
        string ans = "";


        int n = s.size();
        string word = "";
        for(int i = 0; i<n; i++){

            if(s[i] == ' '){
                    if(!word.empty()){
                        ans  = word + ' '+ans;
                        word = "";
                    }
            }

            else{
                word += s[i];
            }
        }

        if(!word.empty()) ans = word + ' ' + ans;
          int right = ans.size()-1;
          while(ans[right] == ' '){
            right--;
          }  
         string res = ans.substr(0, right+1);
        return res;
    }
};