class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            mpp[nums[i]]++;
        }
        int ans = 0;
        for(auto &pair : mpp) {
            if(pair.second % k == 0) {
                ans +=  (pair.first * pair.second);
            }
        }
        return ans;
    }
};