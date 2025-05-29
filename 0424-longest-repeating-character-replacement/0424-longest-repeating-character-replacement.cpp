class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int i = 0;
        int j = 0;
        unordered_map<char, int>mpp;
        int n = s.size();
        int maxLen = 0;
        int maxFreq = 0;
        while(j < n){
            mpp[s[j]]++;
            maxFreq = max(maxFreq, mpp[s[j]]);
            int r = (j - i + 1) - maxFreq;
            if(r <= k) {
                 maxLen = max(maxLen, j - i + 1);
            }
            else{
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
            j++;
        }
        return maxLen;
    }   
};