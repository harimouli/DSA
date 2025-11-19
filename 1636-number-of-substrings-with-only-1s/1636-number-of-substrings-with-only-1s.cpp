class Solution {
public:
    int MOD = 1e9+7;
    int numSub(string s) {
        


        
        int right = 0;

        int n = s.size();

        int subStrings = 0;

        while(right<n){
            
            if(s[right] == '1'){
                int left = right;
                while(s[right] == '1' && right < n){
                    subStrings += (right - left + 1) % MOD;
                    subStrings %= MOD;
                    right++;
                }
            }
            right++;

        }

        return subStrings % MOD;
    }
};