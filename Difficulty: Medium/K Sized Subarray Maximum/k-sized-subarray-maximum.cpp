class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        priority_queue<int>pq;
        
        unordered_map<int, int>mpp;
        int n = arr.size();
        int left = 0;
        vector<int> res;
        for(int right = 0; right<n; right++){
            mpp[arr[right]]++;
            pq.push(arr[right]);
            if(right - left + 1 >= k){
                
                while(!pq.empty() && !mpp[pq.top()]){
                    pq.pop();
                }
                if(!pq.empty()) res.push_back(pq.top());
                mpp[arr[left]]--;
                if(mpp[arr[left]] == 0) mpp.erase(arr[left]);
                left++;
            }
        }
        return res;
        
    }
};