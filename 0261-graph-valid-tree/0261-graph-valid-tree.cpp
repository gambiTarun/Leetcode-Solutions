class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> vis(n,0);
        if(cycle(adj,0,-1,vis))
            return false;
        for(int i=0;i<n;i++)
            if(!vis[i])
                return false;
        return true;
    }
    
    bool cycle(unordered_map<int,vector<int>> &adj, int c, int p, vector<int> &vis){
        if(vis[c]==1)
            return true;
        vis[c]=1;
        for(auto n:adj[c])
            if(n!=p && cycle(adj,n,c,vis))
                return true;
        
        return false;
    }
};