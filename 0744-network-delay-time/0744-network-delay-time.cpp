class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        //Constructiing Adjcency list
        vector<vector<pair<int, int>>> adj(n+1);

        for(auto a : times){
            adj[a[0]].push_back({a[1], a[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int>dist(n+1, 1e9);
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            int curNode = node.second;
            int curWeight = node.first;
            for(auto edge : adj[curNode]){
                int adjNode = edge.first;
                int adjWeight = edge.second;

                if(dist[adjNode] > adjWeight + curWeight){
                    dist[adjNode] = adjWeight + curWeight;
                    pq.push({adjWeight + curWeight, adjNode});
                }
            }

        }

        for(int i = 1; i<=n; i++){
            if(dist[i] == 1e9){
                return -1;
            }
        }

        return *max_element(dist.begin()+1, dist.end());


    }
};