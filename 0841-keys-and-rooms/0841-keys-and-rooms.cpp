class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> vis;
        dfs(rooms,vis,0);
        return vis.size()==rooms.size();
    }
    
    void dfs(vector<vector<int>>& rooms, set<int> &vis, int i){
        if(vis.find(i)!=vis.end()) return;
        
        vis.insert(i);
        for(auto n:rooms[i]){
            if(vis.find(n)==vis.end())
                dfs(rooms,vis,n);
        }
    }
};