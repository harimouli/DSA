class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;

        int maxLen = 0;
        int zeroes = 0;
        for(int right = 0; right<n; right++){
            if(nums[right] == 0)zeroes++;
            while(zeroes > 1) {
                if(nums[left] == 0) zeroes--;
                left++;
            }
            maxLen = max(right - left + 1, maxLen);
        }

        
        return maxLen - 1;
      //O(N) -- time 
      // O(1) -- space 
      // well optimized -- all set

    }
};