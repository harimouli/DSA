class Solution {
public:

    bool isVowel(int ch) {
         if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
          }
          else if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'U' || ch == 'O') {
            return true;
          }
        return false;
    }
    string sortVowels(string s) {
        

        
        vector<int> vowels;
       for(char ch :  s) {
           if(isVowel(ch)) {
            vowels.push_back(ch);
           }
       }
        int t = 0;
        sort(vowels.begin(), vowels.end());
       for(int i = 0; i<s.size() && t < vowels.size(); i++){
            if(isVowel(s[i])) {
                s[i] = vowels[t];
                t++;
            }
            
       }

       return s;

    }
};