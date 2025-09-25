class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> cur(n);
        vector<int> prev(n);
        for (int j = 0; j < n; j++) {
            prev[j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <=i; j++) {
                int down = triangle[i][j] + prev[j];
                int diagonal = triangle[i][j] + prev[j + 1];
                cur[j] = min(down, diagonal);
            }
            prev = cur;
        }
        return prev[0];
    }
};