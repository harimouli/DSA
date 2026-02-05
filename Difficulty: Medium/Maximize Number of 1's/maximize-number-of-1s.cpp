class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        
        
        
        
        int left = 0; 
        int n = arr.size();
        int res = 0;
        int count = 0;
        for(int right = 0; right < n; right++){
            if(arr[right] == 0) count++;
            
            while(count > k){
                if(arr[left] == 0) count--;
                left++;
            }
                
            res = max(right - left + 1, res);
        }
        return res;
    }
};
