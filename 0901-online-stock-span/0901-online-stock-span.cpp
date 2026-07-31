class StockSpanner {
public:
    stack<int> st;
    vector<int> arr;
    int i = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        while(!st.empty() && arr[st.top()] <= price) {
            st.pop();
        }
        if(st.empty()) {
            st.push(i);
            i++;
            return i;
        }
        int ans = (i - st.top());
        st.push(i);
        i++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */