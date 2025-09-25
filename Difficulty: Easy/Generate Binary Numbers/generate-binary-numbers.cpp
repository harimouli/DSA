class Solution {
  public:
    string getBinary(int num) {
        
        string bin = "";
        
        while(num != 0) {
            if(num % 2) bin = '1' + bin;
            else bin = '0' + bin;
            num /= 2;
        }
        return bin;
    }
    vector<string> generateBinary(int n) {
        vector<string> ans;
        for(int i = 1; i<=n; i++) {
            ans.push_back(getBinary(i));
        }
        return ans;
        
    }
};