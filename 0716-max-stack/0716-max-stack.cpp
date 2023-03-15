class MaxStack {
public:
    #define pair pair<int,int>
    list<pair> dll;
    map<pair,list<pair>::iterator> mp;
    int t=0;
    MaxStack() {
        
    }
    
    void push(int x) {
        dll.emplace_front(x,t++);
        mp[*dll.begin()] = dll.begin();
    }
    
    int pop() {
        auto i=*dll.begin();
        dll.pop_front();
        mp.erase(i);
        return i.first;
    }
    
    int top() {
        return (*dll.begin()).first;
    }
    
    int peekMax() {
        return (mp.rbegin())->first.first;
    }
    
    int popMax() {
        auto i = (mp.rbegin())->first;
        dll.erase(mp[i]);
        mp.erase(i);
        return i.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */