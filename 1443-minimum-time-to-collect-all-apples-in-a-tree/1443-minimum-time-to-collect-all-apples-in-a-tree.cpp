class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>> adj;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        return dfs(0,-1,adj,hasApple);
    }
    
    int dfs(int c, int p, unordered_map<int,vector<int>> &adj, vector<bool> &hasApple){
        int totaltime = 0, childtime=0;
        for(auto nei:adj[c]){
            if(nei==p)
                continue;
            childtime = dfs(nei,c,adj,hasApple);
            if(childtime || hasApple[nei]) 
                totaltime += childtime + 2;
        }
        return totaltime;
    }
};