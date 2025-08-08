class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k == 0) return 0;
        int left = 0;

        long long product = 1;

        int noOfSubs = 0;
        int n = nums.size();
        for(int right = 0; right<n; right++) {
            product *= nums[right];

            while(product >= k && left <= right){
                product /= nums[left];
                left++;
            }
            

            noOfSubs += (right - left + 1);
        }

        return noOfSubs < 0 ? 0 : noOfSubs;
    }
};