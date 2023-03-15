class LRUCache {
public:
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> dll;
    int size;
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        dll.splice(dll.begin(),dll,mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            dll.splice(dll.begin(),dll,mp[key]);
            mp[key]->second = value;
            return;
        }
        
        if(mp.size()==size){
            mp.erase(dll.rbegin()->first);
            dll.pop_back();
        }
        
        dll.emplace_front(key,value);
        mp[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */