class Solution {
public:

    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        
        
        int n = s.size();
        int left = 0;;
        int vowels = 0;
        int count = 0;
        int res = 0;
        for(int right = 0; right < n; right++){
            if(isVowel(s[right])) count++;

            if(right - left + 1 > k){
                if(isVowel(s[left])) {
                    if(count) count--;
                }
                left++;
            }
          res = max(count , res);
        }

        return res;
    }
};