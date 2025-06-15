class Solution {
  public:
    
    int getMiniQuotient(int divsor, vector<int> &arr){
        
        int val = 0;
        
        for(int i = 0; i<arr.size(); i++){
            val += (arr[i] +  divsor - 1) / divsor;
        }
        return val;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int left = 1;
        int right =arr[n-1];
        
        
       
        int ans = arr[n-1];
        while(left<= right){
            int mid = (right + left) / 2;
            
            int value = getMiniQuotient(mid, arr);
            
            if(value <= k){
                ans = mid;
                right = mid - 1;
                
            }
            else{
                left = mid + 1;
            }
            
        }
        return ans;
    }
};
