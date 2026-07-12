class Solution {
public:


    bool canweMakeBouquet(int day, vector<int>& nums, int k, int m){

        int bouquet = 0;
        int flowers = 0;
        for(int i = 0; i < nums.size(); i++){
            
            
            if(nums[i] <= day){
                flowers++;
                if(flowers == k){
                    flowers = 0;
                    bouquet++;
                    if(bouquet == m) return true;
                }  
            }else{
                flowers = 0;
            }

        }  
        return false; 
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        if(((long long)(m) * (long long ) (k) ) > n) return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());



        int res = -1;

        while(low <=high){

            int mid = low + (high - low) / 2;

            if(canweMakeBouquet(mid, bloomDay, k, m)){
                res = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return res;
    }
};