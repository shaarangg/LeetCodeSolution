class MyStack {
public:
    queue<int> st;
    MyStack() {}
    
    void push(int x) {
        st.push(x);
        for(int i=0; i<st.size()-1; i++){
            st.push(st.front());
            st.pop();
        }
    }
    int pop() {
        int ans = st.front();
        st.pop();
        return ans;
    }
    
    int top() {
        return st.front();
    }
    
    bool empty() {
        return st.empty();
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