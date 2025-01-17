class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rowDelta = {0, 1, 0, -1};
        vector<int> colDelta = {1, 0, -1, 0};
        vector<int> ans;
        int i = 0;
        int j = 0;
        int pos = 0;
        while (ans.size() != m * n) {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = 1000;
            int nextRow = rowDelta[pos] + i;
            int nextCol = colDelta[pos] + j;
            if (nextRow >= m || nextCol >= n || nextRow < 0 || nextCol < 0 ||
                matrix[nextRow][nextCol] == 1000) {
                pos = (pos + 1) % 4;
            }
            i += rowDelta[pos];
            j += colDelta[pos];
        }
        return ans;
    }
};