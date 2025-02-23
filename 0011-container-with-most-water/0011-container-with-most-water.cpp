class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int ans = 0;
        int n = height.size();
        int left = 0;
        int right = n-1;

        while(left <= right){
            int water = (right - left) * min(height[left], height[right]);
            ans = max(water, ans);
            if(height[left] < height[right]) {
                left++;
            }
            else{
                right--;
            }
        }
        
    return ans;
    }
};