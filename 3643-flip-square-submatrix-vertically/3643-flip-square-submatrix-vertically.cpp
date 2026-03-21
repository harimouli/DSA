class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {

        int m = grid.size();
        int n = grid[0].size();

       
        for (int l = y; l < y + k; l++) {
            int startRow = x;
            int endRow = x + k - 1;
                while (startRow <= endRow) {
                    swap(grid[startRow][l] , grid[endRow][l]);
                    startRow++;
                    endRow--;
                }
        }

        return grid;
    }
};