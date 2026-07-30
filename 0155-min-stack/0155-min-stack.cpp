class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()) {
            st.push(value);
            mini = value;
        }
        else if(value < mini) {
            st.push(2 * 1LL * value - mini);
            mini = value;
        }
        else {
            st.push(value);
        }
    }
    
    void pop() {
        long long val = st.top();
        st.pop();
        if(val < mini) {
            mini = 2 * 1LL * mini - val;
        }
    }
    
    int top() {
        long long val = st.top();
        if(val < mini) {
            return mini;
        }
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */