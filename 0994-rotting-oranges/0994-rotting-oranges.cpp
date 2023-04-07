class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.emplace(i,j);
                }
            }
        }
        vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
        int res=0;
        while(!q.empty()){
            int s=q.size();
            // cout<<s<<endl;
            for(int i=0;i<s;i++){
                auto x = q.front();
                q.pop();
                
                for(auto d:dirs){
                    int r = x.first+d[0];
                    int c = x.second+d[1];
                    if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]==1){
                        grid[r][c]=2;
                        q.emplace(r,c);
                    }
                }
            }
            if(!q.empty())
                res++;
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return res;
    }
};