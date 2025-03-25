class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorA = nums[0];
        for(int i = 1; i<nums.size(); i++){
            xorA ^= nums[i];
        }
        int rightMost = xorA ^ (xorA-1) & xorA;

        int b1 = 0;
        int b2 = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] & rightMost){
                b1 ^= nums[i];
            }
            else{
                b2 ^= nums[i];
            }
        }
        return {b1, b2};

    }
};