class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<grid[i][j]<<endl;
                if(grid[i][j]=='1' && explore(grid,i,j))
                    res++;
            }
        }
        return res;
    }
    
    bool explore(vector<vector<char>> &g, int r, int c){
        queue<pair<int,int>> q;
        q.push({r,c});
        vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            // cout<<"sa"<<endl;
            for(auto d:dirs){
                int nr = p.first+d.first;
                int nc = p.second+d.second;
                if(nr>=0 && nr<g.size() && nc>=0 && nc<g[0].size() && g[nr][nc]=='1'){
                    g[nr][nc]='0';
                    q.push({nr,nc});
                }
            }
        }
        return true;
    }
};