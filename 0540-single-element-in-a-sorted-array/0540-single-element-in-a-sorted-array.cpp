class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        

        int xorA = nums[0];
        for(int i = 1; i<nums.size(); i++){
            xorA ^= nums[i];
        }
        return xorA;
    }
};