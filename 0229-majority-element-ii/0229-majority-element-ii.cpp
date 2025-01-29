class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
            int n = nums.size();
            if(n == 1){
                return {nums[0]};
            }
            vector<int> ans;
            unordered_map<int, int> mp;

            for(int i = 0; i<n; i++){
                mp[nums[i]] += 1;
            }
            for(auto &pair : mp){
                if(pair.second > (n / 3)){
                    ans.push_back(pair.first);
                }
            }
            return ans;

    }
};