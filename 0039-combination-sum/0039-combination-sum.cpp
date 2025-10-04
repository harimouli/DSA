class Solution {
public:

    void getCombinations(int i, vector<int> &temp,vector<int> &candidates, int target, int val, vector<vector<int>> &ans) {
        int n = candidates.size();
        if(val == 0) {
            ans.push_back(temp);
            return;
        }
        if(val < 0 || i>= candidates.size()){
            return;
        }


        temp.push_back(candidates[i]);
        getCombinations(i, temp, candidates, target, val - candidates[i], ans);
        temp.pop_back();
        getCombinations(i+1, temp, candidates, target, val, ans);

    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        getCombinations(0, temp,candidates, target, target, ans);
        return ans;
        
    }   
};