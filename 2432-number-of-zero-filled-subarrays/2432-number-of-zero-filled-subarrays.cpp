class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int n = nums.size();

        long long  ans = 0;

        int left = 0;
        int right = 0;

        while(right <n){
            left = right;
            while(right < n && nums[right] == 0) {
                ans += (right - left+ 1);
                right++;
            }
           right++;
        }
        return ans;
    }
};