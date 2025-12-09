class Solution {
public:


    int getMax(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited){
        int m = grid.size();
        int n = grid[0].size();
        

        if(row >= m || row < 0 || col >= n  ||  col < 0) return 0;
        if(grid[row][col] == 0) return 0;

        if(visited[row][col]) return 0;
        visited[row][col] = 1;
        int up =  grid[row][col] + getMax(row-1, col,grid, visited);
        int down = grid[row][col] + getMax(row + 1, col,grid, visited);
        int right = grid[row][col] + getMax(row , col+1, grid,visited);
        int left = grid[row][col] + getMax(row, col-1, grid,visited);
        visited[row][col] = 0;
        return max({up, down, left, right});
    }
    int getMaximumGold(vector<vector<int>>& grid) {

        int m = grid.size();

        int n = grid[0].size();

        vector<vector<int>> visited(m , vector<int>(n, 0));


        int ans = 0;

        for(int  i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] != 0){
                    ans = max(getMax(i, j, grid, visited), ans);
                }
            }
        }

        return ans;


    }  
};