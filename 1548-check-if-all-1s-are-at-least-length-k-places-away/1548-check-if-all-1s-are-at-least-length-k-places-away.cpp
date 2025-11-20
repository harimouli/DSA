class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        

      
        int n = nums.size();
        int sum = 0;
        int prevIndex = 0;
        for(int i = 0; i<n; i++){
           
           if(nums[i] == 1){
             sum += 1;
             if(sum == 2) {
                if((i - prevIndex) - 1 < k) return false;
                sum = 1;
             }
             prevIndex = i;
             cout<<prevIndex<<endl;

           }
        }
        return true;
    }
};