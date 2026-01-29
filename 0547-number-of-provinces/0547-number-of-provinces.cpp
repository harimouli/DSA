class Solution {
public:




    void  dfs(int vertex, vector<int>& visited, vector<vector<int>>& adj){
        
        int n = adj.size();
        visited[vertex] = 1;


        for(int col = 0; col<n; col++){
            if(!visited[col] && adj[vertex][col] == 1){
                dfs(col , visited, adj);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();

            vector<int> visited(n, 0);


            int provinces = 0;
            for(int i = 0; i<n; i++){
                if(!visited[i]){
                    dfs(i, visited, isConnected);
                    provinces++;
                }
            }
            return provinces;
    }
};