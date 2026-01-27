class Solution {
  public:
  
  
    bool check(int r, int c, vector<vector<char>> &mat, string& word,int index,  vector<vector<bool>>& visited){
        int m = mat.size();
        int n = mat[0].size();
        

        if(index == word.size() - 1) return true;
        
        visited[r][c] = true;
        if(r > 0 && !visited[r-1][c]  &&  mat[r-1][c] == word[index+1]) {
            if(check(r-1, c, mat, word, index + 1, visited)){
                return true;
            }
        }
        
        if(r + 1 < m &&  !visited[r + 1][c]  && mat[r + 1][c] == word[index + 1]){
            if(check(r + 1, c, mat, word, index + 1, visited)){
                return true;
            }
        } 
        
        if(c > 0 && !visited[r][c-1] && mat[r][c-1] == word[index + 1]){
            if(check(r, c -1,  mat, word, index + 1, visited)){
                return true;
            }
        }
        
        if(c + 1 < n && !visited[r][c + 1]  && mat[r][c + 1] == word[index + 1]){
            if(check(r, c + 1, mat, word, index + 1, visited)){
                return true;
            }
        }
        
        visited[r][c] = false;
        return false;
        
    }
    
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        
        
        
        
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++){
                if(mat[i][j] == word[0]){
                    if(check(i, j, mat, word, 0, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};