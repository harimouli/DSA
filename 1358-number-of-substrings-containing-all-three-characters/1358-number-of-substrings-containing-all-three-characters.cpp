class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int left = 0; 

        int n = s.size();
        vector<int> hash = {0, 0, 0};
        int res = 0;
        for(int right = 0; right < n; right++){
            hash[s[right] - 'a']++;

            while(hash[0] != 0 &&  hash[1] != 0 && hash[2] != 0){
                res = res + n - right;
                hash[s[left] - 'a']--;
                left++;
            }
        }
        return res;

    }
};