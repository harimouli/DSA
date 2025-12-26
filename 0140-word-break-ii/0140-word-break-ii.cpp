class Solution {
public:


   
    void getValidSentence(int ind, string &s,  string temp, vector<string> &res, unordered_map<string, bool>&mpp){

        int n = s.size();

        if(ind == n){
            temp.pop_back();
            res.push_back(temp);
            return;
        }

            string curr = "";
        for(int j = ind; j<n; j++){
            curr += s[j];
            if(mpp[curr]){
                getValidSentence(j + 1, s,temp + curr + " ", res, mpp);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        

        vector<string> res; 

        unordered_map<string, bool> mpp;
        for(auto word : wordDict){
            mpp[word] = true;
        }
        getValidSentence(0, s,"", res, mpp);

        return res;
    }
};