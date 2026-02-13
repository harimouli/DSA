class Solution {
public:

    bool isSame(const unordered_map<int, int>& mp){
        if(mp.empty()) return true;

        int firstValue = mp.begin()->second;

        for(const auto &[key, value]: mp){
            if(value != firstValue){
                return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        
        


        int n = s.size();
        int maxLen = 0;
        for(int i = 0; i<n; i++){
            unordered_map<int, int>mpp;
            for(int j = i; j  < n; j++){
                mpp[s[j]]++;

                if(isSame(mpp)){
                    maxLen = max(j  - i + 1, maxLen);
                }
            }   
        }
        return maxLen;


    }
};