class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
       
        for(int  i = n-1; i>=2; i--) {
            int cur = nums[i];
            if(cur < nums[i-1] + nums[i-2]) {
                return cur + nums[i-1] + nums[i-2];
            }
        }
        return 0;
    }
};