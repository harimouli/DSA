class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>grid(m, vector<int>(n ,0));
        vector<vector<int>>visited(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>>q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 0){
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int r = cur.first.first;
            int c = cur.first.second;
            int dist = cur.second;
            if(r > 0 && mat[r-1][c] == 1 && !visited[r-1][c]){
                q.push({{r-1, c}, dist+1});
                grid[r-1][c] = dist+1;
                visited[r-1][c] =1;
            }
            if(r + 1 <m && mat[r+1][c] == 1 && !visited[r+1][c]){
                q.push({{r+1, c}, dist+1});
                grid[r+1][c] = dist+1;
                visited[r+1][c] = 1;
            }
            if(c > 0 && mat[r][c-1] == 1 && !visited[r][c-1]){
                q.push({{r, c-1}, dist+1});
                grid[r][c-1] = dist+1;
                visited[r][c-1] = 1;
            }
            if(c + 1 < n&& mat[r][c+1] == 1 && !visited[r][c+1]){
                q.push({{r, c+1}, dist+1});
                grid[r][c+1] = dist + 1;
                visited[r][c+1] = 1;
            }
        }
        return grid;
    }
};