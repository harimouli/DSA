class Solution {
public:

    void getComb(int ind, string res, vector<string>& s, vector<string>& ans) {



            

            if(res.size() == s.size()) {
                ans.push_back(res);
                return;
            }


            for(int i = 0; i<s[ind].size(); i++){
                string temp = s[ind];
                getComb(ind + 1, res + temp[i], s, ans);
            }
    }
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char, string>mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        vector<string> s;
        for(char c : digits){
            s.push_back(mpp[c]);
        }

        vector<string> ans;
        string res = "";
        cout<<s.size()<<endl;
        getComb(0, res, s, ans);
        return ans;
    }
};