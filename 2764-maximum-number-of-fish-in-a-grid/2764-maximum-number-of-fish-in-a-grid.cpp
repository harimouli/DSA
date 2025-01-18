class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited, int &sum){
        int m = grid.size();
        int n = grid[0].size();
        if(i > 0 && !visited[i-1][j] && grid[i-1][j] > 0){
            visited[i-1][j] = 1;
            sum += grid[i-1][j];
            dfs(i-1, j, grid, visited, sum);
        }
        if(i + 1 < m && !visited[i+1][j] && grid[i+1][j] > 0){
            visited[i+1][j] = 1;
            sum += grid[i+1][j];
            dfs(i+1, j, grid, visited, sum);
        }
        if(j > 0 && !visited[i][j-1] && grid[i][j-1] > 0){
            visited[i][j-1] = 1;
            sum += grid[i][j-1];
            dfs(i, j-1, grid, visited, sum);
        }
        if(j + 1 <n && !visited[i][j+1] && grid[i][j+1] > 0){
            visited[i][j+1] = 1;
            sum += grid[i][j+1];
            dfs(i, j+1, grid, visited, sum);
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n, 0));
        int maxFishes = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                    if(grid[i][j] > 0 && !visited[i][j]){
                        int sum = grid[i][j];
                        visited[i][j] = 1;
                        dfs(i, j, grid, visited, sum);
                        maxFishes = max(sum, maxFishes);

                    }
            }
        }
        return maxFishes;
    
    }
};