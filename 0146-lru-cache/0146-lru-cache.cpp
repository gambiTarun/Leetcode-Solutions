class Node{
public:
    int key,value;
    Node *prev,*next;
    Node(int k, int v, Node* p, Node* n)
        :key(k),value(v),prev(p),next(n)
    {
    }
    
    
};
class LRUCache {
public:
    Node *start,*end;
    unordered_map<int,Node*> mp;
    int size;
    LRUCache(int capacity) {
        start = new Node(-1,-1,NULL,NULL);
        end = new Node(-1,-1,start,NULL);
        start->next = end;
        size = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        
        // remove from curr position
        mp[key]->prev->next = mp[key]->next;
        mp[key]->next->prev = mp[key]->prev;
        
        // insert at the head
        mp[key]->next = start->next;
        start->next->prev = mp[key];
        mp[key]->prev = start;
        start->next = mp[key];
        
        return mp[key]->value;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            mp[key]->value = value;
            get(key);
            return;
        }
        
        if(mp.size()==size){
            Node* del = end->prev;
            mp.erase(del->key);
            end->prev = del->prev;
            del->prev->next = end;
            delete del;
        }
        
        mp[key] = new Node(key,value,start,start->next);
        start->next->prev = mp[key];
        start->next = mp[key];
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */