class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int n = nums.size();
        int left = 0, sum = 0, maxSum = 0;
        unordered_map<int, int>mpp;

        for(int right = 0; right < n; right++){

            sum += nums[right];
            mpp[nums[right]]++;

            while(right - left + 1 > mpp.size()){
                sum -= nums[left];
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
            maxSum = max(sum, maxSum);
        }

        return maxSum;



    }
};