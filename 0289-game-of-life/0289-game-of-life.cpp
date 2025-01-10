class Solution {
public:
    int getLivingNeighbours(int i, int j, vector<vector<int>> &board){
        int livingNeighbours = 0;
        int m = board.size();
        int n = board[0].size();
        if(i > 0 && board[i-1][j] == 1){
            livingNeighbours += 1;
        }
        if(j > 0 && board[i][j-1] == 1){
            livingNeighbours += 1;
        }
        if(j + 1 <n && board[i][j+1] == 1){
            livingNeighbours += 1;
        }
        if(i + 1 <m && board[i+1][j] == 1){
            livingNeighbours += 1;
        }
        if(i -1 >= 0 && j -1 >= 0 && board[i-1][j-1] == 1){
            livingNeighbours += 1;
        }
        if(i - 1 >= 0 && j+1 <n && board[i-1][j+1] == 1){
            livingNeighbours += 1;
        }
        if(i + 1 <m && j-1 >= 0 && board[i+1][j-1] == 1){
            livingNeighbours += 1;
        }
        if(i+ 1 <m && j+1 <n && board[i+1][j+1] == 1){
            livingNeighbours += 1;
        }
        return livingNeighbours;
    }
    void gameOfLife(vector<vector<int>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> neighbours(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int livingNeighbours = getLivingNeighbours(i, j, board);
                neighbours[i][j] = livingNeighbours;
            }
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 1){
                    if(neighbours[i][j] < 2){
                        board[i][j] = 0;
                    }
                    else if(neighbours[i][j] > 3){
                        board[i][j] = 0;
                    }
                }
                else{
                    if(neighbours[i][j]  == 3){
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};