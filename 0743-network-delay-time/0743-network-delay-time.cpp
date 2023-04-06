class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> traveltime(n+1,INT_MAX);
        traveltime[k]=0;
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto t:times)
            adj[t[0]].emplace_back(t[2],t[1]);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.emplace(0,k);
        
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            
            for(auto n:adj[x.second]){
                if(traveltime[n.second]>traveltime[x.second]+n.first){
                    traveltime[n.second] = n.first+traveltime[x.second];
                    pq.emplace(traveltime[n.second],n.second);
                }
            }
        }
        
        int a = *max_element(traveltime.begin()+1,end(traveltime));
        
        return a==INT_MAX?-1:a;
    }
};