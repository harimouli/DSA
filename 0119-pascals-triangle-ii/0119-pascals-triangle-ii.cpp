class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<vector<int>> pascal;
        for(int i =0; i<=rowIndex; i++){
            vector<int> row(i+1);
            for(int j = 0; j<i+1; j++){
                if(i == j || j== 0) row[j] = 1;
                else row[j] = pascal[i-1][j] + pascal[i-1][j-1];
            }
            pascal.push_back(row);
        }
        return pascal[rowIndex];
    
    }
};