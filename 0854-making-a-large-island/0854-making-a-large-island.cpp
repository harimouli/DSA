class DisjointSet {
    public: 
        vector<int> parent;
        DisjointSet(int n){
            parent.resize(n, -1);
        }
        int find(int node){
            if(parent[node] < 0){
                return node;
            }
            return parent[node] = find(parent[node]);
        }
        void unionBySize(int a, int b){
            int parent_a = find(a);
            int parent_b = find(b);
            if(parent_a != parent_b){
                if(parent[parent_a] < parent[parent_b]){
                    int temp = parent[parent_b];
                    parent[parent_b] = parent_a;
                    parent[parent_a] += temp;
                }
                else{
                    int temp = parent[parent_a];
                    parent[parent_a] = parent_b;
                    parent[parent_b] += temp;
                }
            }
        }
        
};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
             int n = grid.size();
        DisjointSet dis_set(n * n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    int node = n * i + j;
                    if(j > 0 && grid[i][j-1] == 1){ //left
                            int adj_node = n*i+(j-1); 
                            if(dis_set.find(node) != dis_set.find(adj_node)){
                                dis_set.unionBySize(node, adj_node);
                            }
                    }   
                    if(j + 1 < n && grid[i][j+1] == 1){ //right
                        int adj_node = n * i + j+1;
                        if(dis_set.find(node) != dis_set.find(adj_node)){
                            dis_set.unionBySize(node, adj_node);
                        }
                    }
                    if(i > 0 && grid[i-1][j] == 1){ //top
                        int adj_node = n * (i-1) + j;
                        if(dis_set.find(node) != dis_set.find(adj_node)){
                            dis_set.unionBySize(node, adj_node);
                        }
                    }
                    if(i + 1 < n && grid[i+1][j] == 1){ // bottom
                        int adj_node = n * (i+1) + j;
                        if(dis_set.find(node) != dis_set.find(adj_node)){
                            dis_set.unionBySize(node, adj_node);
                        }
                    }
                }
            }
        }
        int maxIslands = 0;
        set<int> s;
        for(int i = 0; i<n; i++){
            for(int j = 0; j <n; j++){
                if(grid[i][j] == 0){
                    if(j > 0 && grid[i][j-1] == 1){
                        int adj_node = n * i + (j-1);
                        int final_parent = dis_set.find(adj_node);
                        s.insert(final_parent);
                        
                    }
                    if(j + 1 < n && grid[i][j+1] == 1){
                        int adj_node = n * i + (j+1);
                        int final_parent = dis_set.find(adj_node);
                         s.insert(final_parent);
                    }
                    if(i+1 < n && grid[i+1][j] == 1){
                        int adj_node = n * (i+1) + j;
                        int final_parent = dis_set.find(adj_node);
                         s.insert(final_parent);
                       
                    }
                    if( i > 0 && grid[i-1][j] == 1){
                        int adj_node = n * (i-1) + j;
                        int final_parent = dis_set.find(adj_node);
                         s.insert(final_parent);
                       
                    }
                    int value = 0 ;
                    for(auto x :s){
                        value += abs(dis_set.parent[x]);
                    }
                    if(value + 1 > maxIslands){
                        maxIslands = value  + 1;
                    }
                }
                s.clear();
                
            }
        }
       if(!maxIslands) {
           return n * n;
       }
       return maxIslands;
    }
};