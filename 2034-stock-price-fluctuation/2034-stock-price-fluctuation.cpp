class StockPrice {
public:
    map<int,int> sp;
    multiset<int> s;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(sp.find(timestamp)!=sp.end())
            s.erase(s.find(sp[timestamp]));
        s.insert(price);
        sp[timestamp]=price;
    }
    
    int current() {
        return (--sp.end())->second;
    }
    
    int maximum() {
        return *(--s.end());
    }
    
    int minimum() {
        return *(s.begin());
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */