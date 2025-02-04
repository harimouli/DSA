class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int min_diff = INT_MAX / 2;
        for(int i =0; i<n; i++){
            for(int j = i + 1; j<n; j++){
                for(int k = j + 1; k<n; k++){
                    int sum = nums[i] + nums[j] + nums[k];
                    if(abs(sum - target) < abs(min_diff- target)){
                        min_diff = sum;
                    }
                }
            }
        }
        return min_diff;
    }
};