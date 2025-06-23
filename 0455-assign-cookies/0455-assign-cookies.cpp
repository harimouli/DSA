class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());


        int ans = 0;
        int m = g.size();
        int n = s.size();

        int r = 0;
        int k = 0;
        while(r < m && k < n){
            if(s[k] >= g[r]){
                 ans++;
                 r++;
                 k++;
            }
            else{
               k++; 
            }
        }
        return ans;
    }
};