class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        
        
        int n = arr.size();
        unordered_map<int, int> mpp;
        int left = 0;
        int right = 0;
        int subArrays = 0;
        for(int right = 0; right <n; right++){
            mpp[arr[right]]++;
            
            while(mpp.size() > k){
                mpp[arr[left]]--;
                if(mpp[arr[left]] == 0) mpp.erase(arr[left]);
              left++;
            }
            subArrays += (right - left + 1);
        }
        return subArrays;
        
    }
};