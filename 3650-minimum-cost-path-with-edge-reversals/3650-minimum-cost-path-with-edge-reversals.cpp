class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(n);

       
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

          
            if (currDist > dist[node]) continue;

            for (auto &edge : adj[node]) {
                int nextNode = edge.first;
                int weight = edge.second;

                if (dist[nextNode] > currDist + weight) {
                    dist[nextNode] = currDist + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};
