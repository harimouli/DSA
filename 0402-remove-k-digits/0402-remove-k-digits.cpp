class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<int> stk;

        for(int i = 0; i<num.size(); i++){
            while(!stk.empty() && stk.top() > num[i] && k > 0){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }

        while(!stk.empty() && k > 0){
            stk.pop();
            k--;
        }
        if(stk.empty()) return "0";

        string res = "";

        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }

        while(res.size() > 0 && res.back() == '0'){
            res.pop_back();
        }
        if(res.empty()) return "0";

        reverse(res.begin(), res.end());
        return res;
    }
};