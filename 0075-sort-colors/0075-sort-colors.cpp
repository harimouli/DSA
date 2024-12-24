class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid= 0;
        int high = n-1;
        while(mid<=high){
            if(nums[mid] == 0){
                int temp = nums[mid];
                nums[mid] = nums[low];
                nums[low] = temp; 
                low += 1;
                mid += 1;
            }
            else if (nums[mid] == 2){
                int temp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = temp;
                high = high - 1;
            }
            else {
                mid += 1;
            }
        }
    }
};