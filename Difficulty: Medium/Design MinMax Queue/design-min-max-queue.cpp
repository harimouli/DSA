class SpecialQueue {

  public:
        map<int, int> mpp;
        queue<int>pq;
    void enqueue(int x) {
        pq.push(x);
        mpp[x]++;
    }

    void dequeue() {
        if(pq.empty()) return;
        
        int ele = pq.front();
        pq.pop();
        mpp[ele]--;
        if(mpp[ele] == 0) mpp.erase(ele);
        
    }

    int getFront() {
       return pq.front();
    }

    int getMin() {
        return mpp.begin()->first;
    }

    int getMax() {
        return mpp.rbegin()->first;
    }
};