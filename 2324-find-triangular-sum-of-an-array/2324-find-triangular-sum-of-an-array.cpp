class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];

        for(int i = 1; i<n; i++){
            nums[i-1] = (nums[i - 1] + nums[i]) % 10;
        }
        nums.pop_back();

        return triangularSum(nums);
    }
};