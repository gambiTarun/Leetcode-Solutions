class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        
        unordered_map<int,vector<int>> mp;
        set<int> vis;
        for(auto e:connections){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
    
        
        int c=0;
        for(int i=0;i<n;i++){
            if(vis.find(i)==vis.end()){
                dfs(mp, i, vis);
                c++;
            }
        }
        return c-1;
    }
    
    void dfs(unordered_map<int,vector<int>> &m, int n, set<int> &vis){
        vis.insert(n);
        
        for(auto i:m[n])
            if(vis.find(i)==vis.end())
                dfs(m,i,vis);
    }
};