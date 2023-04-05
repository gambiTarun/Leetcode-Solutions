class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(auto e:prerequisites){
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int> res,vis(numCourses,0);
        for(int i=0;i<numCourses;i++)
            if(!dfs(adj, i, vis, res))
                return {};
        
        return res;
    }
    
    bool dfs(unordered_map<int,vector<int>> &adj, int s, vector<int> &vis, vector<int> &res){
        if(vis[s]==1){
            return false;
        }
        else if(vis[s]==0){
            vis[s]=1;
            for(auto nei:adj[s]){
                if(!dfs(adj,nei,vis,res))
                    return false;
            }
            res.push_back(s);
            vis[s]=2;
        }
        return true;
    }
};