class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;

        for(int i = 0; i<grid.size(); i++){
            for(auto val : grid[i]){
                values.push_back(val);
            }
        }
        sort(values.begin(), values.end());

        for(int val : values){
            if(abs(val - values[0]) % x != 0){
                return -1;
            }
        }
        int operations = 0;
        int median = values[values.size() / 2];
        for(int val : values){
            operations += abs(val - median) / x;
        }
        return operations;

    }
};