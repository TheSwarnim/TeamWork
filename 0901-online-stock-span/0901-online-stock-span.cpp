class StockSpanner {
public:
    StockSpanner() {
    
    }
    
    stack<pair<int, int>> st;
    
    int next(int price) {
        int ttl = 1;
        while(!st.empty() && st.top().first <= price){
            ttl += st.top().second;
            st.pop();
        }
        st.push({price, ttl});
        return ttl;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */