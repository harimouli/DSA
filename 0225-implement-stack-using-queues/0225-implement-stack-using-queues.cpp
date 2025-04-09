class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int len = q.size();

        q.push(x);
        for(int i = 0; i<len; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.empty()){
            return -1;
        }
        int ele = q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        if(!q.empty()){
            return q.front();
        }
        return -1;
    }
    
    bool empty() {
        if(q.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */