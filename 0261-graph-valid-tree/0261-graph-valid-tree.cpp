class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()<n-1)
            return false;
        vector<vector<int>> mp(n);
        for(auto e:edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        
        set<int> vis;
        if(cycle(mp,vis,0,0))
            return false;
        
        return vis.size()==n;
    }
    bool cycle(vector<vector<int>> &mp, set<int> &vis, int c, int p){
        if(vis.find(c)!=vis.end())
            return true;
        
        vis.insert(c);
        
        for(auto n:mp[c]){
            if(n!=p && cycle(mp,vis,n,c))
                return true;
        }
        return false;
    }
};