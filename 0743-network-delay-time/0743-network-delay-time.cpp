class Solution {
public:
    #define dpair pair<int,int>
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<dpair, vector<dpair>, greater<dpair>> pq;
        unordered_map<int, vector<pair<int,int>>> m;
        
        vector<int> vis(n+1, 0);
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        pq.emplace(0,k);
        
        for(auto t:times){
            m[t[0]].push_back(make_pair(t[1],t[2]));
        }
            
        while(!pq.empty()){
            int x = pq.top().second; pq.pop();
            // cout<<x<<endl;
            // if(vis[x]) continue;
            // vis[x] = 1;
            
            for(auto nei:m[x]){
                if(dist[nei.first]>dist[x]+nei.second){
                    dist[nei.first] = dist[x]+nei.second;
                    pq.emplace(dist[nei.first],nei.first);
                }
            }
        }
        
        int ans=*max_element(dist.begin()+1,dist.end());
        
        return ans==INT_MAX?-1:ans;
    }
};