class Solution {
public:
    int getMaxArea(vector<int> prefixSum){
            int n = prefixSum.size();
            int left = 0;
            int right = n-1;

            int maxArea = 0;

           

           for(int i = 0; i<n ; i++){
                int mini = prefixSum[i];

                for(int j = i; j<n; j++){
                    if(prefixSum[j] == 0) break;
                    mini = min(mini , prefixSum[j]);
                    int area = (j - i + 1 ) * mini;
                    maxArea = max(maxArea, area);
                }
           }


      return maxArea;


    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
            int m = matrix.size();
            int n = matrix[0].size();

            vector<int> prefixSum(n, 0);

            int ans = 0;
            for(int i = 0; i<m; i++){
                for(int j = 0; j<n; j++){  // if '0' 
                    if(matrix[i][j] == '1') prefixSum[j]++;
                    else prefixSum[j] = 0;
                }
                ans = max(ans, getMaxArea(prefixSum));
            }
            return ans;        
    }
};