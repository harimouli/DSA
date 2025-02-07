class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
       sort(nums.begin(), nums.end());
        set<vector<int>> s;
       for(int i = 0; i<n; i++){
            for(int j = i + 1; j<n; j++){
                int k = j + 1;
                int x = n -1;
                while(k < x){
                    long long sum =(long long) nums[i] + nums[j] + nums[k] + nums[x];
                    if(sum == target){
                        vector<int> temp;
                        temp = {nums[i], nums[j], nums[k], nums[x]};
                        sort(temp.begin(), temp.end());
                        s.insert({temp});
                        k++;
                        x--;
                    }
                    else if(sum > target){
                        x--;
                    }
                    else if(sum < target){
                        k++;
                    }
                }
            }
       }
       vector<vector<int>>result;
       for(auto q : s){
        result.push_back(q);
       }
       return result;
        
    }
};