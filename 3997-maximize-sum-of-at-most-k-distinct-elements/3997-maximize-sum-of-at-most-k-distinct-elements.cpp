class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        

        sort(nums.begin(), nums.end(), greater<int>());

        

        vector<int> ans;
       
        for(int i = 0; i<nums.size(); i++) {
            if(i == 0) ans.push_back(nums[0]);

            else if(ans.back() != nums[i] && ans.size() < k) ans.push_back(nums[i]); 
        }
        return ans;

    }
};