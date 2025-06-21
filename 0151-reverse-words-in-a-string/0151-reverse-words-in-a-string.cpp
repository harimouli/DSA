class Solution {
public:


    void reverseString(string &s, int start, int end){
        while(start <= end){
            swap(s[start++], s[end--]);
        }
    }
    string reverseWords(string s) {
        

        int n = s.size();
        int i = 0;
        int j = 0;
        int start = 0;
        int end = 0;
        reverseString(s, 0, n - 1);
        while(j < n){


                while(j < n && s[j] == ' '){
                    j++;
                }
                if(j >= n) break;

                start = i;

                while(j < n && s[j] != ' '){
                    s[i++] = s[j++];
                }

                 end = i - 1;

                 reverseString(s, start, end);

                 if(j < n){
                    s[i++] = ' ';
                 }
        }
         if(i > 0 && s[i-1] == ' ') i--;
        return s.substr(0, i);

    }
};