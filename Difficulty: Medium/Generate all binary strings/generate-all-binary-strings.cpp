class Solution {
  public:
  
    void f(int i, int n, vector<string> &res, string s){
        
        if(i == n){
            
            res.push_back(s);
            return;
        }
        
        f(i + 1, n, res, s + '0');
        f(i + 1, n, res, s + '1');
    }
    vector<string> binstr(int n) {
        vector<string> res;
        string s = "";
        
        f(0, n, res, s);
        sort(res.begin(), res.end());
        return res;
          
    }
};