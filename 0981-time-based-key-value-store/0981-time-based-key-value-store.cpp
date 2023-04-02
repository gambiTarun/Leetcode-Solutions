class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        int l=0,r=mp[key].size()-1,m;
        while(l<=r){
            m=l+(r-l)/2;
            if(mp[key][m].first < timestamp)
                l = m+1;
            else if(mp[key][m].first > timestamp)
                r = m-1;
            else
                return mp[key][m].second;
        }
        if(r<0)
            return "";
        return mp[key][r].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */