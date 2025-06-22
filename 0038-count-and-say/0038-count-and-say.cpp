class Solution {
public:
    string countAndSay(int n) {

            if(n == 1) return "1";

            string prev = countAndSay(n-1);
            int len = prev.size();

            int cnt = 1;
            string ans = "";

            for(int i = 1; i<len; i++){
                if(prev[i] == prev[i-1])cnt++;
                else {
                    ans += ('0' + cnt);
                    ans += prev[i-1];
                    cnt = 1;
                }
            }

            ans += ('0' + cnt);
            ans += prev[len-1];

            return ans;

    }
};