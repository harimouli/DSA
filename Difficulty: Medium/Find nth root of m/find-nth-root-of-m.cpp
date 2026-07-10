class Solution {
  public:
  
     long long pow(int mid, int N){
            long long val = 1;
           for(int i = 1; i<=N; i++){
                val = val * 1LL*  mid;
           } 
        return val;
    }
    int nthRoot(int n, int m) {
        
        
        
        int low = 0;

        int high = m;
        if(m == 1) return 1;
        while(low <= high) {

            int mid = low + (high - low) / 2;
            
             long long val = pow(mid, n);
             if(val == m) return mid;
             else if(val < m){
                low = mid + 1;
             }else{
                high = mid  -1;
             }
              
        }
    return -1;
        
    }
};