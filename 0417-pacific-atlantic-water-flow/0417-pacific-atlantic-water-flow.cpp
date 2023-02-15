class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        set<pair<int,int>> pcf;
        set<pair<int,int>> atl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0)
                    pcf.emplace(i,j);
                if(i==m-1||j==n-1)
                    atl.emplace(i,j);
            }
        }
        
        explore(pcf, heights);
        explore(atl, heights);
        vector<vector<int>> res;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pcf.find({i,j})!=pcf.end() && atl.find({i,j})!=atl.end())
                    res.push_back({i,j});
            }
        }
        return res;
    }
    
    void explore(set<pair<int,int>> &p, vector<vector<int>>& heights){
        int m=heights.size();
        int n=heights[0].size();
        queue<pair<int,int>> q;
        for(auto i:p)
            q.push(i);
        
        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            
            for(auto d:dirs){
                int a = x.first+d[0];
                int b = x.second+d[1];
                if(a>=0 && a<m && b>=0 && b<n && p.find({a,b})==p.end() && heights[x.first][x.second]<=heights[a][b]){
                    p.emplace(a,b);
                    q.emplace(a,b);
                }
            }
        }
    }
};