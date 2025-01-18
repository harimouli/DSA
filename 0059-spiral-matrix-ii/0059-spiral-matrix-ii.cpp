class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n, vector<int>(n, 0));
        vector<int> rowDelta = {0, 1, 0, -1};
        vector<int> colDelta = {1, 0, -1, 0};

        int pos = 0;
        int row  = 0;
        int col = 0;
        int tracker = 1;
        while(tracker <= n * n){
            matrix[row][col] = tracker;
            int nextRow = rowDelta[pos] + row;
            int nextCol = colDelta[pos] + col;
            if(nextRow < 0 || nextCol < 0 || nextCol >= n || nextRow >= n || matrix[nextRow][nextCol] != 0){
                pos = (pos + 1) % 4;
            }
            tracker += 1;
            row = rowDelta[pos] + row;
            col = colDelta[pos] + col;
        }
        return matrix;

    }

};