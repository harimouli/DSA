class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
       
        
       int left = 0;
       int sum = 0;
       int n = arr.size();
       int maxSum = sum;
        for(int right; right < n; right++) {
            sum += arr[right];
            if(right - left + 1 >  k){
                sum -= arr[left];
                left++;
            }
            maxSum = max(sum , maxSum);
        }
        return maxSum;
        
    }
};