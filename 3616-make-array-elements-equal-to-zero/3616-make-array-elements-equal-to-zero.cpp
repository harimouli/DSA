class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for(int i = 1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0) {
                int rightSum = prefixSum[n-1] - prefixSum[i];
                if(rightSum == prefixSum[i]) cnt += 2;
                else if(rightSum == prefixSum[i] - 1 || prefixSum[i] == rightSum - 1 ) cnt++;
            }
        }
        return cnt;



    }
};