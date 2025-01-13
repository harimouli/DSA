class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        for(auto k : s){
            mp[k] += 1;
        }
        int count = 0;
        for(auto &pair : mp){
            while(pair.second >= 3){
                count += 2;
                pair.second -= 2;
            }
        }
        return s.length() - count;
    }
};