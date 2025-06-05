class Solution {
public:


    int maxRectArea(vector<int>& arr){


        int maxArea = 0;
        int n = arr.size();

        stack<int> stk;

        for(int i = 0; i<n; i++){


            while(!stk.empty() && arr[stk.top()] >= arr[i]){
                
                int index = stk.top();
                stk.pop();
                int pse = stk.empty() ? -1: stk.top();

                maxArea = max(maxArea, arr[index] * (i - pse - 1));
            }
            stk.push(i);
        }

        while(!stk.empty()) {
            int index = stk.top();
            stk.pop();
            int pse = stk.empty() ? -1 : stk.top();

            maxArea = max(maxArea, (arr[index] * (n - pse -1)));
        }
        return maxArea;


    }
    vector<vector<int>> colPrefixSum(vector<vector<char>>& matrix){
            

            int m = matrix.size();
            int n = matrix[0].size();
            vector<vector<int>> prefixSum(m, vector<int>(n));
            for(int j = 0; j<n; j++){
                int sum  = 0;

                for(int i = 0; i<m; i++){

                    sum =  sum + (matrix[i][j] - '0');

                    if(matrix[i][j] == '0'){
                        prefixSum[i][j] = 0;
                        sum = 0;
                    }
                    prefixSum[i][j] = sum;
                }
            }

        return prefixSum;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<vector<int>> prefixSum = colPrefixSum(matrix);

        int maxArea = 0;
        int m = matrix.size();
        for(int i = 0; i<m; i++){

            maxArea = max(maxArea, maxRectArea(prefixSum[i]));
        }

        return maxArea;


    }
};