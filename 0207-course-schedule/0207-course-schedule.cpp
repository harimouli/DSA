class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        queue<int> q;
        int count = 0;
        for(auto edge : prerequisites) {
            int a = edge[0];
            int b = edge[1];
            adj[b].push_back(a);
        }
        for(int i = 0; i<numCourses; i++){
            for(auto x : adj[i]){
                inDegree[x]++;
            }
        }

        for(int i = 0; i<numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            count++;
            for(auto node : adj[cur]){
                inDegree[node]--;
                if(inDegree[node] == 0) q.push(node);
            }
        }

        
        return (count == numCourses);
        
    }
};