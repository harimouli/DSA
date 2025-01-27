class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for(int i =0; i<numRows; i++){
            vector<int> row(i+1);
            for(int j = 0; j<i+1; j++){
                if(i == j || j== 0) row[j] = 1;
                else row[j] = pascal[i-1][j] + pascal[i-1][j-1];
            }
            pascal.push_back(row);
        }
        return pascal;
    
    }
};