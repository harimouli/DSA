class Solution {
    struct cell{
        int height;
        int col;
        int row;
        cell(int _height, int _col, int _row):height(_height),col(_col),row(_row){}
        bool operator<(const cell& other) const{
            return height>=other.height;
        }
    };
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int tot = 0;
        int m = heightMap.size(), n = heightMap[0].size();
        if(m<=2||n<=2)return 0;
        auto comp = [](cell i, cell j){
            if(i.height==j.height)return i.row<j.row;
            return i.height<j.height;
        };
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<cell> pq;
        int level = 0;
        for(int i=0;i<m;++i){
            pq.push(cell(heightMap[i][0],i,0));
            pq.push(cell(heightMap[i][n-1],i,n-1));
            visited[i][0]=true;
            visited[i][n-1]=true;
        }
        for(int i=0;i<n;++i){
            pq.push(cell(heightMap[0][i],0,i));
            pq.push(cell(heightMap[m-1][i],m-1,i));
            visited[0][i]=true;
            visited[m-1][i]=true;
        }
        while(!pq.empty()){
            cell top = pq.top();
            pq.pop();
            level = max(level, top.height);
            for(int i = 0;i<4;++i){
                int c = top.col+dir[i][0];
                int r = top.row+dir[i][1];
                if(c<0||c==m||r<0||r==n||visited[c][r]){
                    continue;
                }
                visited[c][r] = true;
                if(heightMap[c][r]<level){
                    tot+=(level-heightMap[c][r]);
                }
                pq.push(cell(heightMap[c][r],c,r));

            }
        }
        return tot;
    }
};