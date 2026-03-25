class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
       int m = grid.size();
        int n = grid[0].size();
        int MOD = 12345;
        vector<vector<int>>res(m, vector<int>(n));
        int suffix = 1;
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0 ; j--){
                res[i][j] = suffix;
              suffix = (suffix * (grid[i][j] % MOD))% MOD;
            }
        }
        int prefix = 1;

        for(int i = 0; i<m; i++){
            for(int  j = 0; j<n; j++){
                res[i][j] = (res[i][j] * prefix) % MOD;
                prefix = (prefix * (grid[i][j] % MOD)) % MOD;
            }
        }
      
        return res;
    }
};