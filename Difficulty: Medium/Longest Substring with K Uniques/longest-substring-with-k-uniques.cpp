// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        
        int  n = s.size();
        int left = 0;
        int right = 0;
        int maxLen = -1;
        unordered_map<char, int> mpp;
        
        while(right < n) {
            mpp[s[right]]++;
            if(mpp.size() > k){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0) mpp.erase(s[left]);
              left++;
            }
            else if(mpp.size() == k){
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
            
        } 
        return maxLen < k ? -1 : maxLen;
        
    }
};