class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        int n = nums.size();
        vector<vector<int>> ans;

        for(int num = 0; num<(1 << n); num++){
            vector<int> temp;
            for(int i = 0; i<nums.size(); i++){
                if(num & (1 << i)){
                    temp.push_back(nums[i]);
                }
            }
            sort(temp.begin(),temp.end());
            s.insert(temp);
        }
        for(auto sub : s){
            ans.push_back(sub);
        }
        return ans;
    }
};