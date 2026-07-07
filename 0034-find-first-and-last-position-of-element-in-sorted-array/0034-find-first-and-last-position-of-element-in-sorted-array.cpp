class Solution {
public:
    int lastPos(vector<int> &nums, int target) {

        int n = nums.size();


        int res = -1;

        int low = 0;
        int high = n - 1;


        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] <= target){
                if(nums[mid] == target) {
                    res = mid;
                }
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return res;
    }
    int firstPos(vector<int>& nums, int target) {

        int n = nums.size();

        int res = -1;

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            
                if(nums[mid] >= target){
                    if(nums[mid] == target){
                        res= mid;
                    }
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstInd  = firstPos(nums, target);
        int lastInd = lastPos(nums, target);
       return {firstInd, lastInd};
    }
};