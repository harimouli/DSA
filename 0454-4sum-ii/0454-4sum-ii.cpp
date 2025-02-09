class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {

        unordered_map<int, int> mp;
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                int sum = nums3[i] + nums4[j];
                mp[sum] += 1;
            }
        }
        int count = 0;

        for (int k = 0; k < nums1.size(); k++) {
            for (int x = 0; x < nums2.size(); x++) {
                int temp = -(nums1[k] + nums2[x]);
                count += mp[temp];
            }
        }

        return count;
    }
};