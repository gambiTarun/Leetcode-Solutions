class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> traveltime(n,INT_MAX);
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto t:times)
            adj[t[0]].emplace_back(t[2],t[1]);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.emplace(0,k);
        
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            
            traveltime[x.second-1] = min(traveltime[x.second-1],x.first);
            
            if(!adj.count(x.second))
                continue;
            
            for(auto n:adj[x.second])
                if(traveltime[n.second-1]==INT_MAX)
                    pq.emplace(n.first+x.first,n.second);
        }
        
        for(int i=0;i<n;i++)
            if(traveltime[i]==INT_MAX)
                return -1;
        
        return *max_element(begin(traveltime),end(traveltime));
    }
};