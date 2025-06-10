class Solution {
public:
    int maxDifference(string s) {
        

        unordered_map<char, int>mpp;

        for(int i = 0; i<s.size(); i++){
                mpp[s[i]]++;
        }


        int maxOddFreq = 1;
        int minEvenFreq = INT_MAX;

        for(auto &pair : mpp){
            if(pair.second % 2 == 1){
                maxOddFreq = max(maxOddFreq, pair.second);
            }
            else{
                minEvenFreq = min(minEvenFreq, pair.second);
            }
        }

        if(minEvenFreq == INT_MAX) minEvenFreq = 0;
        return maxOddFreq - minEvenFreq;
    }
};