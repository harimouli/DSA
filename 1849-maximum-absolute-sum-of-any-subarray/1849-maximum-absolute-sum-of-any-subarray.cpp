class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefixSum = 0;
        int prefixMaxSum = 0;
        int prefixMinSum = 0;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            prefixSum += nums[i];
            prefixMaxSum = max(prefixMaxSum, prefixSum);
            prefixMinSum = min(prefixMinSum, prefixSum);
        }
        return (prefixMaxSum - prefixMinSum);
    }
};