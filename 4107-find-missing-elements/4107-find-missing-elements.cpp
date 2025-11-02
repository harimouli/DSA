class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int maxi = nums[n-1];
        int mini = nums[0];
        
        vector<int> res;
        int ind = 0;
        while(mini != maxi){
            if(nums[ind] != mini){
               res.push_back(mini);

            }
            else{
                ind++;
            } 
            mini++;
           
           
        }

        return res;



    }
};