class Solution {
public:
    void bfs(int cur, vector<vector<int>> rooms, vector<int> &visited){
        queue<int>q;

        q.push(cur);
        visited[cur] = 1;
        while(!q.empty()){
            auto edge = q.front();
            q.pop();
            for(auto e : rooms[edge]){
                if(!visited[e]){
                    q.push(e);
                    visited[e] = 1;
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<int> visited(n);
        bfs(0, rooms, visited);
        for(int i =0; i<n; i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};