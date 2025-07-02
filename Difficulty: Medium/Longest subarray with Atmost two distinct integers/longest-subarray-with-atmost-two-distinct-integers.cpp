class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int, int> mpp;
        int n = arr.size();
        int left = 0;
        int maxLen = 0;
        for(int right = 0; right<n; right++){
            mpp[arr[right]]++;
            if(mpp.size() > 2){
                    mpp[arr[left]]--;
                    if(mpp[arr[left]] == 0) mpp.erase(arr[left]);
                    left++;
            }
            maxLen = max(right - left + 1, maxLen);
        }
        
        return maxLen;
    }
};