class MyQueue {
public:
    stack<int> q;
    MyQueue() {}
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        stack<int> temp;
        int l = q.size();
        for(int i=0; i<l; i++){
            temp.push(q.top());
            q.pop();
        }
        int ans = temp.top();
        temp.pop();
        l = temp.size();
        for(int i=0; i<l; i++){
            q.push(temp.top());
            temp.pop();
        }
        return ans;
    }
    
    int peek() {
        stack<int> temp;
        int l = q.size();
        for(int i=0; i<l; i++){
            temp.push(q.top());
            q.pop();
        }
        int ans = temp.top();
        l = temp.size();
        for(int i=0; i<l; i++){
            q.push(temp.top());
            temp.pop();
        }
        return ans;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */