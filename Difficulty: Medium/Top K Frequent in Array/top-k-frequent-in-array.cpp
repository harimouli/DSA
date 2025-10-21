class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        
        int n = arr.size();
        
        unordered_map<int, int>mpp;
        for(int i = 0; i<n; i++){
            mpp[arr[i]]++;
        }
        priority_queue<pair<int, int>>pq;
        
        
        for(auto &p : mpp){
            pq.push({p.second, p.first});
        }
        
        vector<int> ans;
        
        for(int i = 0; i<k; i++){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
      return ans;
    }
};
