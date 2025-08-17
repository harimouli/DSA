class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        


        int minLen = INT_MAX;
        int left = 0;
        int n = nums.size();

        int sum = 0;

        for(int right  = 0; right < n; right++) {
                sum += nums[right];
            while(sum >= target && left<= right) {
                    minLen = min(right - left+ 1, minLen);
                    sum -= nums[left];
                    left++;
            }            
        }
        if(minLen == INT_MAX) return 0;
        return minLen;
    }
};