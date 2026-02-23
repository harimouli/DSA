class Solution {
public:
    bool hasAllCodes(string s, int k) {
        

        if(s.size() < k) return false;
        long long  val = 1 << k;
        unordered_map<string, bool>mpp;

        for(int right = 0; right <= s.size() - k; right++){
            
            string word = s.substr(right, k);
            mpp[word]= true;
        }

        if(val == mpp.size()) return true;
        return false;
    }
};