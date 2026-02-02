class Solution {
public:

    int getMaxi(vector<int> & nums){
        int n = nums.size();
        int sum = 0; 
        int maxSum = INT_MIN;

        for(int x : nums){
            sum += x;
            maxSum = max(sum , maxSum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }

    int getMini(vector<int> & nums){
        int n = nums.size();
        int sum = 0;
        int minSum = INT_MAX;

        for(int x : nums){
            sum += x;
            minSum = min(minSum, sum);
            if(sum > 0) sum = 0;
        }
        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        



        int totalSum = 0;

        for(int x: nums) totalSum += x;

        int globalMax = getMaxi(nums);
        int globalMin = getMini(nums);
        if(globalMax < 0) return globalMax;
        return max(globalMax, totalSum - globalMin);

    }
};