class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, queue<int>> nextRain;
        unordered_set<int> fullLakes;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        // Step 1: Precompute all future rain days for each lake
        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0)
                nextRain[rains[i]].push(i);
        }
        
        // Step 2: Iterate day by day
        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                int lake = rains[i];
                nextRain[lake].pop(); // remove current rain day
                
                // if already full -> flood
                if (fullLakes.count(lake)) return {};
                fullLakes.insert(lake);
                
                // if lake will rain again, push its next occurrence
                if (!nextRain[lake].empty())
                    pq.push({nextRain[lake].front(), lake});
                
                ans[i] = -1;
            } 
            else {
                // dry day
                if (!pq.empty()) {
                    auto [nextDay, lake] = pq.top();
                    pq.pop();
                    fullLakes.erase(lake);
                    ans[i] = lake;
                } else {
                    // dry any lake (doesn't matter)
                    ans[i] = 1;
                }
            }
        }
        return ans;
    }
};