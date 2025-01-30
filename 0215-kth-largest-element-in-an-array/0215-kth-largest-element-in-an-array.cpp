class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int i = 0; i<n; i++){
            pq.push(nums[i]);
        }
        int ans;
        while( k > 0){
            ans = pq.top();
            pq.pop();
            k -= 1;
        }
        return ans;
    }
};