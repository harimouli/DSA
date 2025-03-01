class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] = nums[i] * 2;
                nums[i+1] =0;
            }
        }
       int nonZeroIndex = 0;
       for(int i = 0; i<n; i++){
            if(nums[i] != 0){
                nums[nonZeroIndex] = nums[i];
                nonZeroIndex++;
            }
       }
       while(nonZeroIndex < n){
            nums[nonZeroIndex] = 0;
            nonZeroIndex++;
       }
        return nums;
    }
};