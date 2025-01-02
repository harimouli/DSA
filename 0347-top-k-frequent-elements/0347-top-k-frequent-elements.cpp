class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>mp;
        priority_queue<pair<int, int>>pq;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]] += 1;
        }
        for(auto &pair: mp){
            pq.push({pair.second, pair.first});
        }
        for(int i = 0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};