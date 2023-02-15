class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> mp(n);
        for(auto e:edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        set<int> vis;
        int c=0;
        for(int i=0;i<n;i++)
            if(vis.find(i)==vis.end() && dfs(i,mp,vis))
                c++;
        
        return c;
    }
    
    bool dfs(int i, vector<vector<int>> &mp,set<int> &vis){
        vis.insert(i);
        
        for(auto n:mp[i])
            if(vis.find(n)==vis.end())
                dfs(n,mp,vis);

        return true;
    }
};