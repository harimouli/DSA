class Solution {
  public:
    int substrCount(string &s, int k) {
        int n = s.size();
        
        unordered_map<int, int>mpp;
        int ans = 0;
        int left = 0;
        for(int right = 0; right < n; right++){
            mpp[s[right]]++;
            if(right - left + 1  >= k) {
                  if(mpp.size() == k-1) ans++;
                  mpp[s[left]]--;
                  if(mpp[s[left]] == 0) mpp.erase(s[left]);
            left++;
            }
        }
        return  ans;
    }
};