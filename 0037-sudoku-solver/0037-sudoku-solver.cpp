class Solution {
public:

    bool isSafe(char digit,int row, int col, vector<vector<char>>&board){



        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        




        for(int i = 0; i<9; i++){
            if(board[row][i] == digit) return false;

            if(board[i][col] == digit) return false;
        }


        for(int i = startRow; i<startRow + 3; i++){
            for(int j = startCol; j<startCol + 3; j++){
                    if(board[i][j] == digit) return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == '.') {

                    for (int d = 1; d <= 9; d++) {
                        if (isSafe('0' + d, i, j, board)) {
                            board[i][j] = '0' + d;
                            if(solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }

                    return false;
                }
               
            }
        }

        return true;

    }
    void solveSudoku(vector<vector<char>>& board) {

       solve(board);
    }
};