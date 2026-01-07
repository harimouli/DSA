class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {

        
        unordered_map<int, int> mpp;
        
        int left = 0;
        int n = arr.size();
        vector<int> res;
        for(int right = 0; right<n; right++){
            mpp[arr[right]]++;
            if(right - left  + 1 >= k){
                
                res.push_back(mpp.size());
                mpp[arr[left]]--;
                if(mpp[arr[left]] == 0) mpp.erase(arr[left]);
                left++;
            }
        }
        return res;
        
    }
};