class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       unordered_map<int,int>mp;
       vector<int> ans;
       for(int i = 0; i<nums.size(); i++){
            mp[nums[i]] += 1; 
       }
       for(auto &pair : mp){
            if(pair.second == 1){
                ans.push_back(pair.first);
            }
       }
       return ans;
    }
};