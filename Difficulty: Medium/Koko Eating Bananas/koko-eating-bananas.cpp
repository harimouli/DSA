class Solution {
  public:
  
    int getKokoTime(int capacity, vector<int>& arr){
        int val = 0;
        for(int i = 0; i<arr.size(); i++){
            val += ceil((double)arr[i] / capacity);
        }
        return val;
    }
    int kokoEat(vector<int>& arr, int k) {
        
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int left = 1;
        int right = arr[n-1];
        int ans = arr[n-1];
        while(left <= right){
            
            int mid = (left + right) / 2;
            
            int value = getKokoTime(mid, arr);
            
            if(value <= k){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
        
    }
};