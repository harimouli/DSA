class Solution {
public:
    int getMinDivisor(int divisor, vector<int> &nums){

        int val = 0;

        for(int i = 0; i<nums.size(); i++){
            val = val + (nums[i] + divisor - 1) / divisor;
        }

        return val;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int left = 1;
        int right = nums[n-1];

        int ans = nums[n-1];
        while(left <= right){

            int mid = (right + left) / 2;

            int val = getMinDivisor(mid, nums);

            if(val <= threshold){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return ans;

    }
};