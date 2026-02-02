class Solution {
  public:
  
  
    int getMax(vector<int> & arr){
        int n = arr.size();
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i = 0; i<n ; i++){
            sum += arr[i];
            maxSum = max(maxSum, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
    
    int getMin(vector<int> & arr){
         int n = arr.size();
        int minSum = INT_MAX;
        int sum = 0;
        
        
        for(int i = 0; i < n; i++){
            sum += arr[i];
            minSum = min(minSum, sum);
            if(sum > 0) {
                sum = 0;
            }
        }
        return minSum;
    }
    int maxCircularSum(vector<int> &arr) {
            
        int total = 0;
        
        for(int num : arr){
            total += num;
        }
        
        
        int maxi = getMax(arr);
        int mini = getMin(arr);
        
        if(maxi < 0) return maxi;
        return max(maxi, total - mini);
     
        
    }
};