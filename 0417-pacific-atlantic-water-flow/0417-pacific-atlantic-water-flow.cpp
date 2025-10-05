class Solution {
public:
//type 0-> pacific and 1-> atlantic
int m;
int n;

    vector<vector<int>> directions={{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> bfs(vector<vector<int>> &heights, int type){
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                if(type==0 && (r==0 || c==0)){
                    visited[r][c]=1;
                    q.push({r,c});
                }
                if(type==1 && (r==m-1 || c==n-1)){
                    visited[r][c]=1;
                    q.push({r,c });
                }
            }
        }

        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;

            for(auto d: directions){
                int x_=x+d[0];
                int y_=y+d[1];

                if(x_>=0 && x_<m && y_>=0 && y_<n && visited[x_][y_]==0 && heights[x][y]<=heights[x_][y_]){
                    visited[x_][y_]=1;
                    q.push({x_, y_});
                }
            }
        }
        return visited;
    }

    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<bool>>& visited){
        visited[x][y]=true;

        for(auto d: directions){
            int x_=x+d[0];
            int y_=y+d[1];

            if(x_>=0 && x_<m && y_>=0 && y_<n && !visited[x_][y_] && heights[x][y]<=heights[x_][y_]){
                dfs(heights, x_, y_, visited);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();

        // auto visitedP=bfs(heights, 0);
        // auto visitedA=bfs(heights, 1);

        // vector<vector<int>> ans;
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(visitedP[i][j] && visitedA[i][j]){
        //             ans.push_back({i, j});
        //         }
        //     }
        // }

        vector<vector<bool>> visitedP(m, vector<bool>(n, false));
        vector<vector<bool>> visitedA(m, vector<bool>(n, false));

        //for the pacific ocean
        // in the 0th row
        for(int i=0; i<n; i++) dfs(heights, 0, i, visitedP);
        // in the 0th col
        for(int j=0; j<m; j++) dfs(heights, j, 0, visitedP);

        //for the atlantix
        //in the  m-1 th row
        for(int i=0; i<n; i++) dfs(heights, m-1, i, visitedA);
        //in the n-1 th col
        for(int j=0; j<m; j++) dfs(heights, j, n-1, visitedA);


        vector<vector<int>> ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visitedP[i][j] && visitedA[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};