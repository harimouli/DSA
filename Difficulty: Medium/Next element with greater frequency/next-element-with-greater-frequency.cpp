class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        
        unordered_map<int, int>hash;
        stack<pair<int, int>> stk;
        int n = arr.size();
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            hash[arr[i]]++;
        }
        
        for(int i = n-1; i>=0; i--){
            while(!stk.empty() && hash[arr[i]] >= stk.top().second){
                stk.pop();
            }
        
            ans[i] = stk.empty() ? -1 : stk.top().first;
            stk.push({arr[i], hash[arr[i]]});
        }
        return ans;
        
    }
};
