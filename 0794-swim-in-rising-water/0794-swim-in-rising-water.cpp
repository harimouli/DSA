class Solution {
private:
    bool isSafe(const int& x, const int& y, const int& n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // Create a distance matrix and visited matrix
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        vector<vector<int>> vis(n, vector<int>(n, 0));
        dist[0][0] = 0;
        vis[0][0] = 1;

        // Create a minHeap to get minimum distance path first
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});

        // Apply Dijkstra's algorithm
        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();

            int time = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;

            // Try to move in all 4 directions
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isSafe(nx, ny, n) && !vis[nx][ny]) {
                    if (dist[nx][ny] > max(time, grid[nx][ny])) {
                        dist[nx][ny] = max(time, grid[nx][ny]);
                        pq.push({dist[nx][ny], {nx, ny}});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }

        return dist[n - 1][n - 1];
    }
};