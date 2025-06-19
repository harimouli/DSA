class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.size();
        vector<int> maps(256, 0);
        vector<int> mapt(256, 0);


        for(int i = 0; i <n; i++){
            if(maps[s[i]] != 0 || mapt[t[i]] != 0){
                if(maps[s[i]] != mapt[t[i]]){
                    return false;
                }
            }

            maps[s[i]] = i + 1;
            mapt[t[i]] = i + 1;
        }
        return true;

    }
};