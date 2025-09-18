class TaskManager {
public:
       
        set<pair<int, pair<int, int>>> st;
        unordered_map<int, pair<int, int>>mpp;
        TaskManager(vector<vector<int>>& tasks) {

            mpp.clear();
            st.clear();
            for(auto task : tasks) {
                int userId = task[0];
                int taskId = task[1];
                int priority = task[2];
                st.insert({priority, {taskId, userId}});
                mpp[taskId] = {priority, userId};
            }
        }
    
    void add(int userId, int taskId, int priority) {
      mpp[taskId] = {priority, userId};
      st.insert({priority, {taskId, userId}});
    }
    
    void edit(int taskId, int newPriority) {
        
       int userId = mpp[taskId].second;
       int oldPriority = mpp[taskId].first;
       mpp[taskId] = {newPriority, userId};
       st.erase({oldPriority, {taskId, userId}});
       st.insert({newPriority, {taskId, userId}});

    }
    
    void rmv(int taskId) {
        int userId = mpp[taskId].second;
       int priority = mpp[taskId].first;
       mpp.erase(taskId);
       st.erase({priority, {taskId, userId}});
    }
    
    int execTop() {
            if(st.empty()) return -1;

            auto it = st.rbegin();
       
            int taskId = it->second.first;
            int userId = it->second.second;
            rmv(taskId);
            return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */