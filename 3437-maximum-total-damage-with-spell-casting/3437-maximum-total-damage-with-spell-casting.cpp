class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> damageSum;
        for (auto p : power)
            damageSum[p] += p;

        vector<long long> keys;
        for (auto& it : damageSum)
            keys.push_back(it.first);
        sort(keys.begin(), keys.end());

        int n = keys.size();
        vector<long long> dp(n, 0);
        dp[0] = damageSum[keys[0]];

        for (int i = 1; i < n; i++) {
            long long take = damageSum[keys[i]];
            int j = i - 1;
            while (j >= 0 && keys[i] - keys[j] < 3)
                j--;

            if (j >= 0)
                take += dp[j];

            dp[i] = max(dp[i - 1], take);
        }

        return dp.back();
    }
};