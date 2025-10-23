class Solution {
public:

    void getSubs(int index, vector<vector<int>> &res, vector<int> &nums, vector<int> &temp){
        int n = nums.size();

        if(index == n){
            res.push_back(temp);
            return;
        }


        temp.push_back(nums[index]);

        getSubs(index + 1, res, nums, temp);

        temp.pop_back();

        for(int i = index + 1; i<n; i++){
            if(nums[index] != nums[i]) {
                getSubs(i, res, nums, temp);
                return;
            }
        }

       getSubs(n, res, nums, temp);


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> temp;

        getSubs(0, res, nums, temp);
        return res;



    }
};