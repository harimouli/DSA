class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();

        int threshold = n / 3;

        unordered_map<int, int> mpp; 
        vector<int> res;

        for(int i  = 0; i  < n; i++){
            mpp[nums[i]]++;
        }

        for( auto &pair : mpp){
            if(pair.second > threshold){
                res.push_back(pair.first);
            }
        }
        return res;
    }
};