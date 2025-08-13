class Solution {
public:

   
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        



        int preColor = image[sr][sc];
        image[sr][sc] = color;
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>>visited(m, vector<int>(n, 0));
      


        queue<pair<int,int>>pq;
        pq.push({sr, sc});
        visited[sr][sc] = 1;
        while(!pq.empty()) {
            int row = pq.front().first;
            int col = pq.front().second;
            pq.pop();

            if(row > 0 && image[row-1][col] == preColor && !visited[row-1][col]) {
                pq.push({row-1, col});
                visited[row-1][col] = 1;
                image[row-1][col] = color;
            }
            if(row + 1 < m && image[row+1][col] == preColor && !visited[row+1][col]){
                pq.push({row+1, col});
                visited[row+1][col] = 1;
                image[row+1][col] = color;
            }
            if(col > 0 && image[row][col-1] == preColor && !visited[row][col-1]){
                pq.push({row, col-1});
                visited[row][col-1] = 1;
                image[row][col-1] = color;
            }
            if(col + 1  < n && image[row][col+1] == preColor && !visited[row][col+1]){
                pq.push({row, col+1});
                visited[row][col+1] = 1;
                image[row][col+1] = color;
            }

        }

        return image;
        
    }
};