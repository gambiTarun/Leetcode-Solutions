class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        for(auto e:prerequisites)
            adj[e[0]].push_back(e[1]);
        
        vector<int> vis(numCourses,0);
        for(int i=0;i<numCourses;i++)
            if(cycle(adj,i,vis))
                return false;
        // cout<<vis.size()<<endl;
        return true;
    }
    
    bool cycle(vector<vector<int>> &adj, int s, vector<int> &vis){
        if(vis[s]==1)
            return true;
        // cout<<s<<endl;
        if(vis[s]==0){
            vis[s]=1;
            for(auto n:adj[s])
                if(cycle(adj,n,vis))
                    return true;
            vis[s]=2;
        }
        return false;
    }
};