class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0;
        int rightMax = 0;


        int left = 0;
        int right = n-1;
        int water = 0;
        while(left <= right){
            if(leftMax <= rightMax){
                if(height[left] >= leftMax) leftMax = height[left];
                else water  = water +  leftMax - height[left];  
                left++;
            }
            else {
                if(height[right] >= rightMax) rightMax = height[right];
                else water = water + rightMax - height[right];
                right--;
            }
        }
        return water;
    }
};