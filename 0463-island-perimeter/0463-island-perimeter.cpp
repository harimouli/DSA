class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        


        int rowSize = grid.size();
        int colSize = grid[0].size();

        int perimeter = 0;
        for(int i = 0; i<rowSize; i++){
            
            for(int j = 0; j<colSize; j++){
             if(grid[i][j] == 1) {
                


              if(i == 0) perimeter++;
              if(i == rowSize -1) perimeter++;
              if(j == 0) perimeter++;
              if(j == colSize - 1) perimeter++;
               if(i > 0 && grid[i-1][j] == 0) perimeter++;
               if(j + 1 < colSize && grid[i][j+1] == 0) perimeter++;
               if(i + 1 < rowSize && grid[i+1][j] == 0) perimeter++;
               if(j > 0 && grid[i][j-1] == 0) perimeter++;
                cout<<perimeter << endl;
             }
          }
        }
        return perimeter;
    }
};