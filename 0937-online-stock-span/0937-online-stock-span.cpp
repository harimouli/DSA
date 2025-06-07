class StockSpanner {
public:
    stack<pair<int, int>> stk;
    int index = -1;
    StockSpanner() {
        while(!stk.empty()){
            stk.pop();
        }
        index = -1;
    }
    
    int next(int price) {
        index += 1;
        while(!stk.empty() && stk.top().first <= price){
            stk.pop();
        }
        int ans = index - (stk.empty() ? -1 : stk.top().second);
        stk.push({price, index});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */