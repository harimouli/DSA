class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        set<vector<int>>s;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            int j = i + 1; 
            int k = n-1;
            while(j <k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> triplet;
                    triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    s.insert({triplet});
                    j++;
                    k-= 1;
                }
                else if(nums[i] + nums[j] + nums[k] > 0) {
                    k -= 1;
                }
                else{
                    j++;
                }
            }
        }
        vector<vector<int>> result;
        for(auto temp : s){
            result.push_back(temp);
        }
        return result;
    }
};