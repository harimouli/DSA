class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        

        int n = strs.size();
        string ans = "";

        string first = strs[0];
        string last = strs[n-1];


        int len = min(first.size(), last.size());


        for(int i =0; i<len; i++){
            if(first[i] != last[i]){
                return ans;
            }
            ans += first[i];
        }
        return ans;




    }
};