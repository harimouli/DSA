class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        


        int n1 = nums1.size();
        vector<int> ans(n1);
        stack<int> stk;
        int n = nums2.size();
        vector<int>nge(n);

        for(int i = n-1; i >= 0; i--){

            while(!stk.empty() && stk.top() <= nums2[i]){
                stk.pop();
            }
            if(stk.empty()){
                nge[i] = -1;
            }
            else{
                nge[i] = stk.top();
            }
            stk.push(nums2[i]);
        }


        for(int i = 0; i<n1; i++){
            for(int j = 0; j<nge.size(); j++){
                if(nums1[i] == nums2[j]){
                    ans[i] = nge[j];
                }
            }
        }
        return ans;



    }
};