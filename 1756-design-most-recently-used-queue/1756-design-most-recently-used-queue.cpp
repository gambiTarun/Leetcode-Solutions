class MRUQueue {
public:
    list<int> l;
    MRUQueue(int n) {
        while(n)
            l.push_front(n--);
    }    
    
    int fetch(int k) {
        l.splice(l.end(),l,next(l.begin(),k-1));
        return *l.rbegin();
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */