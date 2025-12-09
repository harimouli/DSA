class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int MOD = 1e9 + 7;
        unordered_map<int, int>leftFreq;
        unordered_map<int, int>rightFreq;
        int res = 0;
        for(int num : nums) rightFreq[num]++;

        int n = nums.size();
        for(int i = 0; i<n; i++){
            int mid = nums[i];

            rightFreq[mid]--;

            int left = leftFreq[2 * mid];
            int right = rightFreq[2 * mid];

            res  = (res + 1LL * left * right) % MOD; 

            leftFreq[mid]++;
        }

       return res;
    }
};