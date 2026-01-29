// User function Template for C++

class Solution {
  public:
  
    void dfs(int vertex, vector<int> &visited, vector<vector<int>>&adj){
        int n = adj.size();
        visited[vertex] = 1;
        
        for(int edge = 0; edge < n; edge++){
            if(!visited[edge] && adj[vertex][edge]){
                dfs(edge, visited, adj);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        
        
        
        
        int count = 0;
        
        vector<int> visited(V, 0);
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                count++;
                dfs(i, visited, adj);
            }
        }
        return count;
    }
};