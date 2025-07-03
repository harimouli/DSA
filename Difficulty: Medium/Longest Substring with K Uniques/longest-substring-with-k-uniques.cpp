class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        
        
        
        unordered_map<int, int>mpp;
        int n = s.size();
        int left = 0;
        int ans = 0;
        for(int right = 0; right<n; right++){
            mpp[s[right]]++;
            
            if(mpp.size() > k){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        if(mpp.size() < k) return -1;
        return ans;
    }
};