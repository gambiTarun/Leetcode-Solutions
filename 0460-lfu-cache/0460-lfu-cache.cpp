class LFUCache {
public:
    unordered_map<int, pair<int,int>> mp;
    unordered_map<int, list<int>> freq;
    unordered_map<int, list<int>::iterator> pos;
    int size,minFreq;
    LFUCache(int capacity) {
        size=capacity;
        minFreq=0;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        freq[mp[key].second].erase(pos[key]);
        mp[key].second++;
        freq[mp[key].second].push_front(key);
        pos[key] = freq[mp[key].second].begin();
        if(freq[minFreq].size()==0) minFreq++;
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(get(key)!=-1){
            mp[key].first=value;
            return;
        }
        if(mp.size()==size){
            int del = *freq[minFreq].rbegin();
            freq[minFreq].pop_back();
            mp.erase(del);
            pos.erase(del);
        }
        mp[key] = {value,1};
        freq[1].emplace_front(key);
        pos[key] = freq[1].begin();
        minFreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */