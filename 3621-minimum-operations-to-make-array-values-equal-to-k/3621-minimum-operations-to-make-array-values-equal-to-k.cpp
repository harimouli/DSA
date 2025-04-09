class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        

        int n = nums.size();

        unordered_map<int, int> mp;

        int count = 0;

        for(int i = 0; i<n; i++){
            if(mp.find(nums[i]) == mp.end()){
                int diff = nums[i] - k;
                if(diff < 0) return -1;
                if(diff != 0) count++;
            }
            mp[nums[i]]++;
        }
        return count;
    }
};