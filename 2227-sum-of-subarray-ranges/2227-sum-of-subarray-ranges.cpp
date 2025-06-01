class Solution {
public:
    vector<int> findPGE(vector<int> &arr){
        int n = arr.size();
        stack<int> stk;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            
            while(!stk.empty() && arr[stk.top()] < arr[i]){
                stk.pop();
            }

            ans[i] = stk.empty() ? -1: stk.top();
            stk.push(i);
        }
        return ans;
    }
    vector<int> findNGE(vector<int> &arr){
        int n = arr.size();

        stack<int> stk;

        vector<int> ans(n);

        for(int i = n - 1; i>=0; i--){

            while(!stk.empty() && arr[stk.top()] <= arr[i]){
                stk.pop();
            }

            ans[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        return ans;
    }
    long long  sumSubarrayMaxs(vector<int> &arr){

            long long sum = 0;
            vector<int> nge =  findNGE(arr);
            vector<int> pgee = findPGE(arr);

            for(int i = 0; i<arr.size(); i++){
                
                int left = i - pgee[i];
                int right = nge[i] - i;

                long long freq = left * right * 1LL;

                long long val = (freq * arr[i] * 1LL);
                sum += val;
            }
            return sum;
    }

    vector<int> findNSE(vector<int> &arr){

          
            int n = arr.size();
            vector<int> ans(n);

            stack<int> stk;

            for(int i = n - 1; i>=0; i--){

                while(!stk.empty() && arr[stk.top()] >= arr[i]){
                    stk.pop();
                }

                ans[i] = stk.empty() ? n: stk.top();
                stk.push(i);
            }
            return ans;
    }

    vector<int> findPSEE(vector<int> &arr){
        int n = arr.size();
        stack<int> stk;

        vector<int> ans(n);

        for(int i = 0; i<n; i++){

            while(!stk.empty() && arr[stk.top()] > arr[i]){
                stk.pop();
            }
            ans[i] = stk.empty() ? -1: stk.top();
            stk.push(i);
        }
        return ans;
    }

    long long  sumSubarrayMins(vector<int> &arr){
            long long sum  = 0;

            vector<int> nse = findNSE(arr);
            vector<int> psee = findPSEE(arr);

            for(int i = 0; i<arr.size(); i++){

                int left = i -  psee[i];
                int right = nse[i] - i;

                long long freq = left * right * 1LL;
                long long val = freq * arr[i] * 1LL;
                sum += val;
            }
            return sum;
    }
    long long subArrayRanges(vector<int> &nums) {
        return (sumSubarrayMaxs(nums) - sumSubarrayMins(nums));
    }
};
