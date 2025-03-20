class Solution {
public:
    void getSubsets(int i, vector<int> nums, vector<int> &temp, vector<vector<int>> &ans){
        if(i < 0){

            ans.push_back(temp);
            return;
        }
        getSubsets(i-1, nums, temp, ans);
        temp.push_back(nums[i]);
        getSubsets(i-1, nums, temp, ans);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        getSubsets(n-1 ,nums, temp, ans);
        return ans;
    }
};