class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        vector<string> strBuck(n+1);
        unordered_map<char, int> mpp;
        string ans = "";
        for(int i = 0; i<n; i++){
            mpp[s[i]]++;
        }

        for(auto &pair : mpp){
           
                strBuck[pair.second] += string(pair.second, pair.first);
        }

        for(int i = n; i>=0; i--){
                if(strBuck[i] != ""){
                    ans += strBuck[i];
                }
        }

        return ans;


    }
};