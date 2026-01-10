class Solution {
  public:
  
  
    int atMostK(const string &s, int k){
        int n = s.size();
        
        vector<int>freq(26, 0);
        int res = 0;
        int left = 0;
        int distinct = 0;
        for(int right = 0; right < n; right++){
          if (freq[s[right] - 'a'] == 0) distinct++;
            freq[s[right] - 'a']++;

            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0) distinct--;
                left++;
            }

            res += (right - left + 1);
        }
       return res;
    }
    
    
    int countSubstr(string& s, int k) {
        int exactlyK = atMostK(s, k) - atMostK(s, k-1);
        return exactlyK;
    }
};