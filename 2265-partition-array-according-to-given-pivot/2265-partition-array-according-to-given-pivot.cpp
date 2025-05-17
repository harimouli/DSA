class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        

        vector<int> greatEle;
        vector<int> smallEle;
        vector<int> ans;
        int pivotCount = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == pivot) {
                pivotCount++;
            }
            else if(nums[i] < pivot){
                smallEle.push_back(nums[i]);
            }
            else {
                greatEle.push_back(nums[i]);
            }
        }

        for(auto num : smallEle){
            ans.push_back(num);
        }
        while(pivotCount != 0){
            ans.push_back(pivot);
            pivotCount--;
        }
        for(auto num : greatEle){
            ans.push_back(num);
        }

        return ans;

    }
};