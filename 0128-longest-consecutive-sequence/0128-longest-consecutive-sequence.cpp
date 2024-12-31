class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
       sort(nums.begin(), nums.end());
        int longSubseq = 1;
        int count = 1;
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i] + 1 == nums[i+1] || nums[i] == nums[i+1]){
                if(nums[i] + 1 == nums[i+1]){
                    count += 1;
                }
                else{
                    count += 0;
                }
            }
            else{
                count = 1;
            }
            longSubseq = max(count, longSubseq);
            
        }
        return longSubseq;
    }
};