class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        



        int n = nums.size();

        int maxLen = 0;
        int left = 0;
        int prevBits = 0;

        for(int right = 0; right < n; right++){
                while((prevBits & nums[right]) != 0){
                    prevBits ^= nums[left];
                    left++;

                }
                prevBits |= nums[right];
                maxLen = max(maxLen, right - left + 1);
                
        }
        return maxLen;

    }
};