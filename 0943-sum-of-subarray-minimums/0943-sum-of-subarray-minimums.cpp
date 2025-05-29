class Solution {
public:
    vector<int> findNse(vector<int> arr){
        int n = arr.size();
        stack<int> stk;

        vector<int> ans(n);

        for(int i = n - 1; i>=0; i--){

            while(!stk.empty() && arr[stk.top()] >= arr[i]){
                stk.pop();
            }
            ans[i] = !stk.empty() ? stk.top() : n;

            stk.push(i);
        }
        return ans;
    }
    vector<int> findPsee(vector<int> arr){
        int n = arr.size();
        stack<int> stk;
        vector<int> ans(n);

        for(int i = 0; i<n; i++){

            while(!stk.empty() && arr[stk.top()] > arr[i]){
                stk.pop();
            }
            ans[i] = !stk.empty() ? stk.top() : -1;
            stk.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
          int mod = (int) (1e9 + 7);
         
        vector<int> nse = findNse(arr);
        vector<int> psee = findPsee(arr);
        int sum = 0;
        for(int i = 0; i<arr.size(); i++){
            int left = i -  psee[i];
            int right = nse[i] - i;

            long long freq  = (left * right * 1LL);

            int val = (freq * arr[i]*1LL) % mod;
            sum = (sum + val) % mod;
        }
        return sum;
    }
};