class MedianFinder {
private:
    priority_queue<int> sm;
    priority_queue<int,vector<int>,greater<int>> lg;
public:
    void addNum(int num) {
        sm.push(num);
        if(sm.size()-lg.size()>=2){
            lg.push(sm.top());
            sm.pop();
        }
        if(sm.size()!=0 && lg.size()!=0 && sm.top()>=lg.top()){
            int temp = lg.top();
            lg.pop();
            lg.push(sm.top());
            sm.pop();
            sm.push(temp);
        }
    }
    
    double findMedian() {
        if((sm.size()+lg.size())%2==0){
            double res = sm.top()+lg.top();
            return res/2;
        }
        double res = sm.top();
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */