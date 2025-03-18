class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorA = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            xorA ^= nums[i];
        }

        int source = xorA ^ k;
        int count = 0;
        while (source != 0) {
            count++;
            source = source & (source - 1);
        }
        return count;
    }
};