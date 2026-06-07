class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        


        int n = nums.size();
        unordered_map<int, int> mpp;

        for(int i = 0; i  < n; i++){

            int value = target - nums[i];

            if(mpp.find(value) != mpp.end()){
                return {mpp[value], i};
            }

            mpp[nums[i]] = i;
        }

        return {-1, -1};
    }
};