class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]] += 1;
        }
        for(auto &pair : mp){
            if(pair.second  % 2 != 0){
                return false;
            }
        }
        return true;
    }
};