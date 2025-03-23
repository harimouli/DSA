class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto road : roads){
            long long a = road[0];
            long long  b = road[1];
            long long  weight = road[2];
            adj[a].push_back({b, weight});
            adj[b].push_back({a, weight});
        }
        priority_queue< pair<long long, long long>,vector<pair<long long ,long long>> ,greater<pair<long long ,long long>> > pq;
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        vector<long long> path(n, 0);
        path[0] = 1;
        pq.push({0, 0}); //{distance, node};
         const long long mod = 1e9 + 7;
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            long long  d = x.first;
            long long cur = x.second;
            for(auto k : adj[cur]){
                long long  neighbour = k.first;
                long long  weight = k.second;
                if(d + weight < dist[neighbour]){
                    dist[neighbour] = d + weight;
                    path[neighbour] = path[cur];
                    pq.push({d+weight, neighbour});
                }
                else if(d +weight == dist[neighbour]){
                    path[neighbour] = (path[cur] + path[neighbour]) % mod;
                }
            }

        }
        return path[n-1]%mod;
    }
};