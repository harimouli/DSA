class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();

        int i = 0;
        int j = 0;
        unordered_set<char> st;
        int maxCount = 0;
        while (j < n) {
            if (st.find(s[j]) == st.end()) {
                st.insert(s[j]);
                if (st.size() > maxCount) {
                    maxCount = st.size();
                }
                j++;
            }
            else  {
                st.erase(s[i]);
                i++;
            }
        }
        return maxCount;
    }
};