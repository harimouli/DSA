class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]] += 1;
        }
        priority_queue<pair<int, int>>pq;
        for(auto &pair : mp){
            pq.push({pair.second, pair.first});
        }
        vector<int> ans;
        for(int i = 0;i<k; i++){
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;

    }
};