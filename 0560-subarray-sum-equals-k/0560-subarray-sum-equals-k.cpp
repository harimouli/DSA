class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int, int>mp;
       int sum = 0;
       int count = 0;
       for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            if(sum == k){
                count ++;
            }
            count += mp[sum - k];
            mp[sum] += 1;
       }
        return count;
    }
};