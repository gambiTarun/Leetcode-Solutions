class MedianFinder {
public:
    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int>> minh;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minh.empty() || num>minh.top()) minh.push(num);
        else maxh.push(num);
            
        if (minh.size() > maxh.size()+1) {
            maxh.push(minh.top());
            minh.pop();
        }
        else if (minh.size()+1 < maxh.size()){
            minh.push(maxh.top());
            maxh.pop();
        }
    }
    
    double findMedian() {
        if(minh.size()>maxh.size()) return minh.top();
        else if(minh.size()<maxh.size()) return maxh.top();
        else return (maxh.top()+minh.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */