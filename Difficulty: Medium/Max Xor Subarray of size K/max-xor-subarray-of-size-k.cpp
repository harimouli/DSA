class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        
        
        
        int n = arr.size(); 
        
        
        
       
        
        
        int left = 0; 
        
        int maxXor = 0;
        
        
        
    
        
        int xorValue = 0;
        for(int right = 0; right <n; right++){
            xorValue ^= arr[right];
            if(right - left  + 1 >= k){
                maxXor = max(xorValue, maxXor);
                xorValue ^= arr[left];
                left++;
            }
        }
        
        return maxXor;
    }
};