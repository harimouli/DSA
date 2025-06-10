class Solution {
  public:
    int countStrings(string &s) {
        
    vector<int> freq(26, 0);
    int n = s.size();

    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    int count = 1;
    bool flag = false;

    for (int i = 0; i < n; i++) {
        count += n - i - 1;

        if (freq[s[i] - 'a'] > 1) {
            count -= freq[s[i] - 'a'] - 1;
            flag = true;
        }

        if (freq[s[i] - 'a'] > 1) {
            freq[s[i] - 'a']--;
        }
    }

    if (!flag) {
        count--;  
    }

    return count;
    }
};
