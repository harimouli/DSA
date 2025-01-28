class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<int> prev = {1};
        for(int i =0; i<=rowIndex; i++){
            vector<int> row(i+1);
            for(int j = 0; j<i+1; j++){
                if(i == j || j== 0) row[j] = 1;
                else row[j] = prev[j-1] + prev[j];
            }
            prev = row;
        }
        return prev;
    
    }
};