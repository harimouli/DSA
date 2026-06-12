class Solution {
public:
    int maxProduct(vector<int>& nums) {
        


        int suffix = 1;
        int prefix = 1;
        int n = nums.size();
        int maxProd = nums[0];
        for(int i = 0; i < n; i++){

            if(prefix == 0) prefix = 1;

            prefix = prefix * nums[i];
            maxProd = max(prefix, maxProd); 
        }


        for(int i = n - 1; i >= 0; i--){
            if(suffix == 0) suffix = 1;
            suffix = suffix * nums[i];
            maxProd = max(suffix, maxProd);
        }
        return maxProd;




    }
};