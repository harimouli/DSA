class Solution {
public:
    void solve(int row, int col, vector<vector<int>>& grid,
               vector<vector<int>>& visited, int& ans, int validBlock) {
        // base
        int m = grid.size();
        int n = grid[0].size();
        visited[row][col] = 1;
        if (grid[row][col] == 2) {
            if (validBlock < 0) ans++;
            visited[row][col] = 0;
            return;
        }

        if(grid[row][col] == -1) return;
        
        if (row > 0 && !visited[row - 1][col] && grid[row - 1][col] != 1 ) {
            solve(row - 1, col, grid, visited, ans, validBlock- 1);
        }

        // down
        if (row + 1 < m && !visited[row + 1][col] && grid[row + 1][col] != 1) {
            solve(row + 1, col, grid, visited, ans, validBlock-1);
        }

        // right

        if (col + 1 < n && !visited[row][col + 1] && grid[row][col + 1] != 1) {
            solve(row, col + 1, grid, visited, ans, validBlock- 1);
        }


        //left 

        if(col > 0 && !visited[row][col - 1] && grid[row][col - 1] != 1){
            solve(row, col - 1, grid, visited, ans, validBlock-1);
        }


        //resetting the visited 
        visited[row][col] = 0;

    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        int validBlock = 0;

        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    validBlock++;
            }
        }

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    solve(i, j, grid, visited, ans, validBlock);
                    break;
                }
            }
        }

        return ans;
    }
};